#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, Q, w[222'230], p[222'230], d[222'230], num[222'230];
int hld[222'230], node_num, seg[4*222'230], lazy[4*222'230], rev[222'230];
vector<int> adj[222'230];

void dfs(int u);
void dfs2(int u);
void sp(int n, int s, int e);
void su(int l, int r, int n = 1, int s = 1, int e = N);
int sq(int i, int n = 1, int s = 1, int e = N);
void u(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 1; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1);
	dfs2(1);
	for (int i = 0; i < Q; ++i)
	{
		int c, d;
		cin >> c >> d;
		u(c, d);
	}
	int ans = -1, ansu, ansv;
	for (int i = 1; i < N; ++i)
	{
		int t = sq(i);
		if (ans < t) { ans = t; ansu = p[rev[i]]; ansv = rev[i]; }
	}
	cout << min(ansu, ansv) << " " << max(ansu, ansv) << " " << ans;

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
	rev[num[u]] = u;
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

void sp(int n, int s, int e)
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
	sp(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { ++lazy[n]; sp(n, s, e); return; }
	int m = s + e >> 1;
	su(l, r, n * 2, s, m);
	su(l, r, n * 2 + 1, m + 1, e);
}

int sq(int i, int n, int s, int e)
{
	sp(n, s, e);
	if (s == e) return seg[n];
	int m = s + e >> 1;
	if (i <= m) return sq(i, n * 2, s, m);
	else return sq(i, n * 2 + 1, m + 1, e);
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