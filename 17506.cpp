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

constexpr int sz = 510, src = 0, snk = 505, INF = 0x3f3f3f3f;
int N, inq[sz], dist[sz];
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
	cin >> N;
	for (int i = 501; i <= 503; ++i)
	{
		int c; cin >> c;
		adj[i].emplace_back(snk, adj[snk].size(), min(N - 3, c - 1), 0);
		adj[snk].emplace_back(i, adj[i].size() - 1, 0, 0);
		adj[i].emplace_back(snk, adj[snk].size(), 1, -1e6);
		adj[snk].emplace_back(i, adj[i].size() - 1, 0, 1e6);
	}
	adj[504].emplace_back(snk, adj[snk].size(), N - 3, 0);
	adj[snk].emplace_back(504, adj[504].size() - 1, 0, 0);
	for (int i = 1; i <= N; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[i].emplace_back(501, adj[501].size(), 1, -a);
		adj[501].emplace_back(i, adj[i].size() - 1, 0, a);
		adj[i].emplace_back(502, adj[502].size(), 1, -b);
		adj[502].emplace_back(i, adj[i].size() - 1, 0, b);
		adj[i].emplace_back(503, adj[503].size(), 1, -c);
		adj[503].emplace_back(i, adj[i].size() - 1, 0, c);
		adj[i].emplace_back(504, adj[504].size(), 1, 0);
		adj[504].emplace_back(i, adj[i].size() - 1, 0, 0);
		adj[src].emplace_back(i, adj[i].size(), 1, 0);
		adj[i].emplace_back(src, adj[src].size() - 1, 0, 0);
	}
	cout << -mcmf().second - (int)3e6;
}