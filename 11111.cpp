#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Edge
{
	int v, p, cp, co;
	Edge(int _v, int _p, int _cp, int _co) : v(_v), p(_p), cp(_cp), co(_co) {}
};

constexpr int sz = 2510, src = 2505, snk = 2506, INF = 0x3f3f3f3f;
int N, M, inq[sz], dist[sz], dn[4] = { 0,0,1,-1 }, dm[4] = { 1,-1,0,0 };
int val[5][5] = { {10,8,7,5,1},{8,6,4,3,1},{7,4,3,2,1},{5,3,2,2,1}, {1,1,1,1,0} };
string A[sz];
pii prv[sz];
vector<Edge> adj[sz];
queue<int> q;

bool spfa()
{
	memset(inq, 0, sizeof inq);
	memset(dist, 0x3f, sizeof dist);
	q.push(src);
	dist[src] = 0;
	inq[src] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for (int i = 0; i < adj[u].size(); ++i)
		{
			auto& e = adj[u][i];
			if (e.cp <= 0) continue;
			if (dist[e.v] > dist[u] + e.co)
			{
				dist[e.v] = dist[u] + e.co;
				prv[e.v].first = u; prv[e.v].second = i;
				if (!inq[e.v]) { q.push(e.v); inq[e.v] = 1; }
			}
		}
	}
	return dist[snk] != 0x3f3f3f3f;
}

pii mcmf()
{
	int fl = 0, co = 0;
	while (spfa())
	{
		int c = 0, f = INF;
		for (int i = snk; i != src; i = prv[i].first)
		{
			auto& e = adj[prv[i].first][prv[i].second];
			f = min(f, e.cp);
			c += e.co;
		}
		fl += f; co += f * c;
		for (int i = snk; i != src; i = prv[i].first)
		{
			auto& e = adj[prv[i].first][prv[i].second];
			e.cp -= f;
			adj[e.v][e.p].cp += f;
		}
	}
	return { fl,co };
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		for (auto& c : A[i])
			if (c == 'F') c--;
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int u = i * M + j;
			if ((i + j) % 2)
			{
				adj[u].emplace_back(snk, adj[snk].size(), 1, 0);
				adj[snk].emplace_back(u, adj[u].size() - 1, 0, 0);
				continue;
			}
			adj[src].emplace_back(u, adj[u].size(), 1, 0);
			adj[u].emplace_back(src, adj[src].size() - 1, 0, 0);
			adj[u].emplace_back(snk, adj[snk].size(), 1, 0);
			adj[snk].emplace_back(u, adj[u].size() - 1, 0, 0);
			for (int k = 0; k < 4; ++k)
			{
				int nn = i + dn[k], nm = j + dm[k];
				if (nn < 0 || nm < 0 || nn >= N || nm >= M) continue;
				int v = nn * M + nm;
				adj[u].emplace_back(v, adj[v].size(), 1, -val[A[i][j] - 'A'][A[nn][nm] - 'A']);
				adj[v].emplace_back(u, adj[u].size() - 1, 0, val[A[i][j] - 'A'][A[nn][nm] - 'A']);
			}
		}
	}
	cout << -mcmf().second;
}