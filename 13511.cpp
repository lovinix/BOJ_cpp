#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int>;

int N, M, node_num, w[100'010], num[100'010], p[100'010], d[100'010], hld[100'010], rev[100'010];
lli seg[4 * 100'010];
tu edge[100'010];
vector<int> adj[100'010];

void dfs(int u);
void dfs2(int u);
void su(int i, int v, int n = 1, int s = 1, int e = N);
lli sq(int l, int r, int n = 1, int s = 1, int e = N);
lli q1(int u, int v);
int q2(int u, int v, int k);
int kth(int u, int v, int k);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		edge[i] = { u,v,c };
	}
	hld[1] = 1;
	dfs(1); dfs2(1);
	for (int i = 1; i < N; ++i)
	{
		auto& [u, v, c] = edge[i];
		su(max(num[u], num[v]), c);
	}
	cin >> M;
	while (M--)
	{
		int f, u, v, k;
		cin >> f;
		if (f == 1)
		{
			cin >> u >> v;
			cout << q1(u, v) << '\n';
		}
		else
		{
			cin >> u >> v >> k;
			cout << q2(u, v, k) << '\n';
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

void su(int i, int v, int n, int s, int e)
{
	seg[n] += v;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m) su(i, v, n * 2, s, m);
	else su(i, v, n * 2 + 1, m + 1, e);
}

lli sq(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return sq(l, r, n * 2, s, m) + sq(l, r, n * 2 + 1, m + 1, e);
}

lli q1(int u, int v)
{
	lli ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret += sq(num[hld[u]], num[u]);
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return ret + sq(num[u] + 1, num[v]);
}

int q2(int u, int v, int k)
{
	int lca, u1 = u, v1 = v;
	while (hld[u1] != hld[v1])
	{
		if (d[hld[u1]] < d[hld[v1]]) swap(u1, v1);
		u1 = p[hld[u1]];
	}
	if (d[u1] > d[v1]) swap(u1, v1);
	lca = u1;
	if (d[u] - d[lca] + 1 == k) return lca;
	else if (d[u] - d[lca] + 1 > k) return kth(u, lca, k);
	else return kth(lca, v, d[v] - d[lca] + 1 - k + d[u] - d[lca] + 1);
}

int kth(int u, int v, int k)
{
	if (d[u] < d[v]) swap(u, v);
	while (k)
	{
		int dif = d[u] - d[hld[u]] + 1;
		if (dif >= k)
			return rev[num[u] - k + 1];
		else
		{
			k -= dif;
			u = p[hld[u]];
		}
	}
	return rev[u];
}