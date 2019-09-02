#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MAX = 100'001;
int N, M, root, node_num, num[MAX], idx[MAX], hld[MAX], w[MAX], d[MAX], p[MAX];
lli seg[4 * MAX], lazy[4 * MAX];
vector<int> adj[MAX];

void dfs(int u);
void dfs2(int u);
void init_HLD(int N, int r);
void pr(int n, int s, int e);
void su(int l, int r, int n = 1, int s = 1, int e = N);
lli sq(int l, int r, int n = 1, int s = 1, int e = N);
void u(int u, int v);
lli q(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	init_HLD(N, 1);
	while (M--)
	{
		char c; int x, y;
		cin >> c >> x >> y;
		if (c == 'P')
			u(x, y);
		else
			cout << q(x, y) << "\n";
	}
}

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
	idx[num[u]] = u;
	for (auto& v : adj[u])
	{
		if (p[v] == u && (cc == -1 || w[cc] < w[v]))
			cc = v;
	}
	if (cc != -1)
	{
		hld[cc] = hld[u];
		dfs2(cc);
	}
	for (auto& v : adj[u])
	{
		if (p[v] == u && v != cc)
		{
			hld[v] = v;
			dfs2(v);
		}
	}
}

void init_HLD(int N, int r)
{
	root = r; p[r] = r; d[r] = hld[r] = node_num = 0;
	dfs(r);
	dfs2(r);
}

void pr(int n, int s, int e)
{
	if (!lazy[n]) return;
	seg[n] += (e - s + 1) * lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[n * 2] += lazy[n];
	lazy[n * 2 + 1] += lazy[n];
	lazy[n] = 0;
}

void su(int l, int r, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] += 1; pr(n, s, e); return; }
	int m = s + e >> 1;
	su(l, r, n * 2, s, m);
	su(l, r, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

lli sq(int l, int r, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return sq(l, r, n * 2, s, m) + sq(l, r, n * 2 + 1, m + 1, e);
}

void u(int u, int v)
{
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		su(num[hld[u]], num[u]);
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	su(num[u] + 1, num[v]);
}

lli q(int u, int v)
{
	lli ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret += sq(num[hld[u]], num[u]);
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return sq(num[u] + 1, num[v]) + ret;
}