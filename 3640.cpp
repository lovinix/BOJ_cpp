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

constexpr int sz = 2010, src = 0, snk = 2005, INF = 0x3f3f3f3f;
int V, E, inq[sz], dist[sz];
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
	while (cin >> V >> E)
	{
		for (int i = 0; i < sz; ++i)
			adj[i].clear();
		for (int i = 1; i <= V; ++i)
		{
			adj[i].emplace_back(i + V, adj[i + V].size(), 1 + (i == 1 || i == V), 0);
			adj[i + V].emplace_back(i, adj[i].size() - 1, 0, 0);
		}
		for (int i = 0; i < E; ++i)
		{
			int u, v, c;
			cin >> u >> v >> c;
			int _u = u + V, _v = v + V;
			adj[_u].emplace_back(v, adj[v].size(), 1, c);
			adj[v].emplace_back(_u, adj[_u].size() - 1, 0, -c);
		}
		adj[src].emplace_back(1, adj[1].size(), 2, 0);
		adj[1].emplace_back(src, adj[src].size() - 1, 0, 0);
		adj[V + V].emplace_back(snk, adj[snk].size(), 2, 0);
		adj[snk].emplace_back(V + V, adj[V + V].size() - 1, 0, 0);
		cout << mcmf().second << "\n";
	}
}