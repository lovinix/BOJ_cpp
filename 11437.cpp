#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50'010;
int N, M, n[MAX], hld[MAX], w[MAX], p[MAX], d[MAX], rev[MAX], cnt;
vector<int> adj[MAX];

void dfs(int u);
void dfs2(int u);
int q(int u, int v);

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
	dfs(1); dfs2(1);
	cin >> M;
	while (M--)
	{
		int u, v;
		cin >> u >> v;
		cout << q(u, v) << "\n";
	}
}

void dfs(int u)
{
	w[u] = 1;
	for (auto& v : adj[u])
	{
		if (!w[v])
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
	n[u] = ++cnt;
	rev[n[u]] = u;
	for (auto& v : adj[u])
	{
		if (p[v] == u && (cc == -1 || w[v] > w[cc]))
			cc=v;
	}
	if(cc!=-1) {hld[cc] = hld[u]; dfs2(cc); }
	for (auto& v : adj[u])
	{
		if (p[v] == u && v != cc)
		{
			hld[v] = v;
			dfs2(v);
		}
	}
}

int q(int u, int v)
{
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		u = p[hld[u]];
	}
	return rev[min(n[u], n[v])];
}