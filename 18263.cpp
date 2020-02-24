#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Pst
{
	int l, r, v;
	Pst() { l = r = v = 0; }
};

constexpr int sz = 100'010;
int N, M, A[sz], num[sz], p[sz], hld[sz], d[sz], w[sz], node_num;
vector<Pst> pst(sz);
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

void su(int i1, int i2, int v, int s = 1, int e = N)
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

int sq(int i1, int i2, int v, int s = 1, int e = N)
{
	if (s > v || e < v) return 0;
	if (s == e) return pst[i2].v - pst[i1].v;
	int m = s + e >> 1;
	if (v <= m) return sq(pst[i1].l, pst[i2].l, v, s, m);
	else return sq(pst[i1].r, pst[i2].r, v, m + 1, e);
}

int lca(int u, int v)
{
	int ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return u;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	dfs(1);
	dfs2(1);
	for (int i = 1; i <= N; ++i)
		su(num[p[i]], num[i], A[i]);

	while(M--)
	{
		int A, B, C, LCA;
		cin >> A >> B >> C;
		LCA = lca(A, B);
		cout << ((sq(num[LCA], num[A], C) + sq(num[p[LCA]], num[B], C))>0);
	}
}