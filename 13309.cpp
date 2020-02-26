#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 200'010;
int N, Q, w[sz], num[sz], d[sz], p[sz], hld[sz], node_num, seg[4 * sz];
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

void su(int i, int v, int n = 1, int s = 1, int e = N)
{
	if (s > i || e < i) return;
	if (s == e) { seg[n] = v; return; }
	int m = s + e >> 1;
	su(i, v, n * 2, s, m);
	su(i, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] && seg[n * 2 + 1];
}

int sq(int l, int r, int n = 1, int s = 1, int e = N)
{
	if (s > r || e < l) return 1;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return sq(l, r, n * 2, s, m) && sq(l, r, n * 2 + 1, m + 1, e);
}

int q(int u, int v)
{
	int ret = 1;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret &= sq(num[hld[u]], num[u]);
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return ret && sq(num[u] + 1, num[v]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 2; i <= N; ++i)
	{
		int u; cin >> u;
		adj[u].emplace_back(i);
	}
	dfs(1);
	dfs2(1);
	for (int i = 1; i <= N; ++i) su(i, 1);
	while (Q--)
	{
		int u, v, f;
		cin >> u >> v >> f;
		if (f == 0)
		{
			cout << (q(u, v) ? "YES" : "NO") << "\n";
		}
		else
		{
			int a = q(u, v);
			cout << (a ? "YES" : "NO") << "\n";
			if (a) su(num[u], 0);
			else su(num[v], 0);
		}
	}
}