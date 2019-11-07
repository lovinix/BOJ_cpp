#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Pst
{
	int l, r, v;
	Pst() : l(0), r(0), v(0) {}
};

const int MAX = (int)INT_MAX * 3;
int N, M, node_num, rev[100'010], w[100'010], num[100'010], p[100'010], hld[100'010], d[100'010];
int arr[100'010];
vector<int> adj[100'010];
vector<Pst> pst(100'010);

void dfs(int u);
void dfs2(int u);
void su(int i1, int i2, int v, int s = 1, int e = 1e6);
int sq(int u, int v, int lca, int plca, int k, int s = 1, int e = 1e6);
int q(int u, int v, int k);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1);
	hld[1] = 1;
	dfs2(1);
	for (int i = 1; i <= N; ++i)
	{
		int u = rev[i];
		su(num[p[u]], i, arr[u]);
	}
	cin >> M;
	while (M--)
	{
		int x, y, k;
		cin >> x >> y >> k;
		cout << q(x, y, k) << "\n";
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

void su(int i1, int i2, int v, int s, int e)
{
	if (s > v || e < v) return;
	pst[i2].v = pst[i1].v + 1;
	if (s == e) return;
	int m = s + e >> 1;
	if (v <= m)
	{
		if (!pst[i2].l || pst[i2].l == pst[i1].l)
		{
			pst[i2].l = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].r == 0)
			pst[i2].r = pst[i1].r;
		su(pst[i1].l, pst[i2].l, v, s, m);
	}
	else
	{
		if (!pst[i2].r || pst[i2].r == pst[i1].r)
		{
			pst[i2].r = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].l == 0)
			pst[i2].l = pst[i1].l;
		su(pst[i1].r, pst[i2].r, v, m + 1, e);
	}
}

int sq(int u, int v, int lca, int plca, int k, int s, int e)
{
	if (s == e) return s;
	int m = s + e >> 1;
	int lcnt = pst[pst[u].l].v + pst[pst[v].l].v - pst[pst[lca].l].v - pst[pst[plca].l].v;
	if (lcnt >= k)
		return sq(pst[u].l, pst[v].l, pst[lca].l, pst[plca].l, k, s, m);
	else
		return sq(pst[u].r, pst[v].r, pst[lca].r, pst[plca].r, k - lcnt, m + 1, e);
}

int q(int u, int v, int k)
{
	int u1 = u, v1 = v;
	while (hld[u1] != hld[v1])
	{
		if (d[hld[u1]] < d[hld[v1]]) swap(u1, v1);
		u1 = p[hld[u1]];
	}
	int lca = d[u1] < d[v1] ? u1 : v1;
	return sq(num[u], num[v], num[lca], num[p[lca]], k);
}