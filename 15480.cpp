#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 100'010;
int N, M, w[sz], p[sz], d[sz], num[sz], hld[sz], node_num;
vector<int> adj[sz];

void dfs(int u)
{
	w[u] = 1;
	for (auto& v : adj[u])
	{
		if (w[v] == 0)
		{
			p[v] = u;
			d[v] = d[u] + 1;
			dfs(v);
			w[u] += w[v];
		}
	}
}

void dfs2(int u)
{
	int cc = -1;
	num[u] = ++node_num;
	for (auto& v : adj[u])
	{
		if (p[v] == u && (cc == -1 || w[v] > w[cc]))
			cc = v;
	}
	if (cc != -1) { hld[cc] = hld[u]; dfs2(cc); }
	for (auto& v : adj[u])
	{
		if (p[v] == u && v != cc)
		{
			hld[v] = v;
			dfs2(v);
		}
	}
}

int lca(int u, int v)
{
	int ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return u;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1);
	dfs2(1);
	cin >> M;
	while (M--)
	{
		int r, u, v;
		cin >> r >> u >> v;
		if (int ru = lca(r, u), rv = lca(r, v), uv = lca(u, v); ru == rv && ru != uv) cout << uv << '\n';
		else cout << (num[ru] > num[rv] ? ru : rv) << '\n';
	}
}