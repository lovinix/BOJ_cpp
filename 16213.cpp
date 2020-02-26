#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

constexpr int sz = 200'010;
int N, M, Q, uf[sz], w[sz], d[sz], p[sz], num[sz], hld[sz], seg[4 * sz], node_num;
vector<int> adj[sz];
tu E[500'010];

int f(int u)
{
	return uf[u] < 0 ? u : uf[u] = f(uf[u]);
}

void m(int u, int v)
{
	int _u = f(u), _v = f(v);
	if (_u == _v) return;
	uf[_u] += uf[_v];
	uf[_v] = _u;
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
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
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

int sq(int l, int r, int n = 1, int s = 1, int e = N)
{
	if (s > r || e < l) return INT_MAX;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return min(sq(l, r, n * 2, s, m), sq(l, r, n * 2 + 1, m + 1, e));
}

int q(int u, int v)
{
	int ret = INT_MAX;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret = min(ret, sq(num[hld[u]], num[u]));
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return min(ret, sq(num[u] + 1, num[v]));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(uf, -1, sizeof uf);
	cin >> N >> M >> Q;
	for (int i = 0; i < M; ++i)
	{
		int u, v, s;
		cin >> u >> v >> s;
		E[i] = { s,u,v };
	}
	sort(E, E + M);
	for (int i = M - 1; i >= 0; --i)
	{
		auto& [s, u, v] = E[i];
		m(u, v);
	}
	dfs(1);
	dfs2(1);
	for (int i = 0; i < M; ++i)
	{
		auto& [s, u, v] = E[i];
		if (p[u] == v) su(num[u], s);
		else if (p[v] == u) su(num[v], s);
	}
	while (Q--)
	{
		int u, v;
		cin >> u >> v;
		cout << q(u, v) << "\n";
	}
}