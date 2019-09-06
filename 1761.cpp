#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;

const int MAX = 40'010;
int N, M, p[MAX], w[MAX], hld[MAX], d[MAX], acc[MAX], num[MAX], cnt;
vector<pii> adj[MAX];

void dfs(int u);
void dfs2(int u, int d);
int q(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	dfs(1);
	dfs2(1,0);
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
	for (auto& [v,t] : adj[u])
	{
		if (w[v]) continue;
		p[v] = u;
		d[v] = d[u] + 1;
		dfs(v);
		w[u] += w[v];
	}
}

void dfs2(int u, int d)
{
	int cc = -1, nd = -1;
	num[u] = ++cnt;
	acc[num[u]] = acc[num[u] - 1] + d;
	for (auto& [v,t] : adj[u])
	{
		if (p[v] == u && (cc == -1 || w[v] > w[cc]))
			cc=v,nd=t;
	}
	if (cc != -1) { hld[cc] = hld[u]; dfs2(cc, nd); }
	for (auto& [v, t] : adj[u])
	{
		if (p[v] == u && v != cc)
		{
			hld[v] = v;
			dfs2(v,t);
		}
	}
}

int q(int u, int v)
{
	int ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret += acc[num[u]] - acc[num[hld[u]] - 1];
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return ret + acc[num[v]] - acc[num[u]];
}
