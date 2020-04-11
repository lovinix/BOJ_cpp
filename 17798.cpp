#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;

struct Edge
{
	int v, p, cp, co;
	Edge(int _v, int _p, int _cp, int _co) : v(_v), p(_p), cp(_cp), co(_co) {}
};

constexpr int sz = 302, src = 0, snk = 301, INF = 0x3f3f3f3f3f3f3f3f;
int N, M, inq[sz], dist[sz];
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
	return dist[snk] != INF;
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

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		adj[i].emplace_back(i + 150, adj[i + 150].size(), 1, 0);
		adj[i + 150].emplace_back(i, adj[i].size() - 1, 0, 0);
		adj[src].emplace_back(i, adj[i].size(), 1, 0);
		adj[i].emplace_back(src, adj[src].size() - 1, 0, 0);
		adj[i + 150].emplace_back(snk, adj[snk].size(), 1, 0);
		adj[snk].emplace_back(i + 150, adj[i + 150].size() - 1, 0, 0);
	}
	while (M--)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].emplace_back(v + 150, adj[v + 150].size(), 1, -c);
		adj[v + 150].emplace_back(u, adj[u].size() - 1, 0, c);
	}
	cout << fixed << setprecision(7) << (-mcmf().second * 0.05);
}