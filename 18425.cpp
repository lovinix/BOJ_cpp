#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int, int>;

const int SZ = 200'010;
int N, num[SZ], p[SZ], d[SZ], w[SZ], hld[SZ], node_num, seg[4 * SZ], lazy[4 * SZ];
lli ans;
vector<int> adj[SZ];
tu A[SZ];

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

void pr(int n, int s, int e)
{
	if (!lazy[n]) return;
	seg[n] += (e - s + 1) * lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[n * 2] += lazy[n];
	lazy[n * 2 + 1] += lazy[n];
	lazy[n] = 0;
}

void su(int l, int r, int n = 1, int s = 1, int e = N)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] += 1; pr(n, s, e); return; }
	int m = s + e >> 1;
	su(l, r, n * 2, s, m);
	su(l, r, n * 2 + 1, m + 1, e);
}

int sq(int i, int n = 1, int s = 1, int e = N)
{
	pr(n, s, e);
	if (s > i || e < i) return 0;
	if (s == e) return seg[n];
	int m = s + e >> 1;
	return sq(i, n * 2, s, m) + sq(i, n * 2 + 1, m + 1, e);
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int a, b, c1, c2;
		cin >> a >> b >> c1 >> c2;
		A[i] = { a,b,c1,c2 };
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1);
	dfs2(1);
	for (int i = 1; i < N; ++i)
		u(i, i + 1);
	for (int i = 1; i < N; ++i)
	{
		auto& [a, b, c1, c2] = A[i];
		if (num[a] > num[b]) swap(a, b);
		if (lli cur = 1LL * sq(num[b]) * c1; cur < c2) ans += cur;
		else ans += c2;
	}
	cout << ans;
}