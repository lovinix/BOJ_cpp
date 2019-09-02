#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long;

const int MAX = 500'010;
const lli MOD = 1LL << 32;
int N, Q, num[MAX], hld[MAX], d[MAX], p[MAX], w[MAX], rn[MAX], node_num;
lli seg[4 * MAX], lazy1[4 * MAX], lazy2[4 * MAX];
vector<int> adj[MAX];

void dfs(int u);
void dfs2(int u);
void init_HLD(int u);
void pr(int n, int s, int e);
void su(int l, int r, int t, int v, int n = 1, int s = 1, int e = N);
lli sq(int l, int r, int n = 1, int s = 1, int e = N);
void u(int u, int v, int t, int val);
lli q(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fill(lazy2, lazy2 + 4 * MAX, 1);
	cin >> N >> Q;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	init_HLD(1);
	while (Q--)
	{
		int f, X, Y, V;
		cin >> f;
		switch (f)
		{
		case 1:
			cin >> X >> V;
			su(num[X], rn[X], 1, V);
			break;
		case 2:
			cin >> X >> Y >> V;
			u(X, Y, 1, V);
			break;
		case 3:
			cin >> X >> V;
			su(num[X], rn[X], 0, V);
			break;
		case 4:
			cin >> X >> Y >> V;
			u(X, Y, 0, V);
			break;
		case 5:
			cin >> X;
			cout << sq(num[X], rn[X]) << "\n";
			break;
		case 6:
			cin >> X >> Y;
			cout << q(X, Y) << "\n";
		}
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
	rn[u] = node_num;
}

void init_HLD(int u)
{
	p[u] = u; d[u] = hld[u] = node_num;
	dfs(u);
	dfs2(u);
}

void pr(int n, int s, int e)
{
	if (lazy2[n] == 1 && lazy1[n] == 0) return;
	seg[n] *= lazy2[n];
	seg[n] %= MOD;
	seg[n] += (e - s + 1) * lazy1[n];
	seg[n] %= MOD;
	if (s == e) { lazy1[n] = 0; lazy2[n] = 1; return; }
	int m = (s + e) >> 1;
	lazy1[n * 2] *= lazy2[n];
	lazy1[n * 2] += lazy1[n];
	lazy1[n * 2] %= MOD;
	lazy2[n * 2] *= lazy2[n];
	lazy2[n * 2] %= MOD;
	lazy1[n * 2 + 1] *= lazy2[n];
	lazy1[n * 2 + 1] += lazy1[n];
	lazy1[n * 2 + 1] %= MOD;
	lazy2[n * 2 + 1] *= lazy2[n];
	lazy2[n * 2 + 1] %= MOD;
	lazy1[n] = 0; lazy2[n] = 1;
}

void su(int l, int r, int t, int v, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r)
	{
		if (t) { lazy1[n] += v; lazy1[n] %= MOD; pr(n, s, e); return; }
		else { lazy1[n] *= v; lazy2[n] *= v; lazy1[n] %= MOD; lazy2[n] %= MOD; pr(n, s, e); return; }
	}
	int m = s + e >> 1;
	su(l, r, t, v, n * 2, s, m);
	su(l, r, t, v, n * 2 + 1, m + 1, e);
	seg[n] = (seg[n * 2] + seg[n * 2 + 1]) % MOD;
}

lli sq(int l, int r, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return (sq(l, r, n * 2, s, m) + sq(l, r, n * 2 + 1, m + 1, e)) % MOD;
}

void u(int u, int v, int t, int val)
{
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		su(num[hld[u]], num[u], t, val);
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	su(num[u], num[v], t, val);
}

lli q(int u, int v)
{
	lli ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret += sq(num[hld[u]], num[u]);
		ret %= MOD;
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return (ret + sq(num[u], num[v])) % MOD;
}