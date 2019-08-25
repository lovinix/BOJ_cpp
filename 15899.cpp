#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Pst
{
	int l, r, v;
	Pst() : l(0), r(0), v(0) {}
};

int N, M, C, clr[200'001], cnt, l[200'001], r[200'001], rev[200'001];
lli ans;
vector<int> adj[200'001];
vector<Pst> pst(200'001);

void dfs(int u);
void u(int i1, int i2, int v, int s = 1, int e = N);
int q(int i1, int i2, int v, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> C;
	for (int i = 1; i <= N; ++i)
		cin >> clr[i];
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1);
	for (int i = 1; i <= N; ++i)
		u(i - 1, i, clr[rev[i]]);
	while (M--)
	{
		int v, c;
		cin >> v >> c;
		ans += q(l[v] - 1, r[v], c);
		ans %= 1'000'000'007;
	}
	cout << ans;
}

void dfs(int u)
{
	l[u] = ++cnt;
	rev[l[u]] = u;
	for (auto v : adj[u])
		if (!l[v]) dfs(v);
	r[u] = cnt;
}

void u(int i1, int i2, int v, int s, int e)
{
	if (s > v || e < v) return;
	pst[i2].v = pst[i1].v + 1;
	if (s == e) return;
	int m = (s + e) >> 1;
	if (v <= m)
	{
		if (pst[i2].l == 0 || pst[i2].l == pst[i1].l)
		{
			pst[i2].l = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].r == 0) pst[i2].r = pst[i1].r;
		u(pst[i1].l, pst[i2].l, v, s, m);
	}
	else
	{
		if (pst[i2].r == 0 || pst[i2].r == pst[i1].r)
		{
			pst[i2].r = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].l == 0) pst[i2].l = pst[i1].l;
		u(pst[i1].r, pst[i2].r, v, m + 1, e);
	}
}

int q(int i1, int i2, int v, int s, int e)
{
	if (s > v) return 0;
	if (e <= v) return pst[i2].v - pst[i1].v;
	int m = (s + e) >> 1;
	if (v <= m)
		return q(pst[i1].l, pst[i2].l, v, s, m);
	return pst[pst[i2].l].v - pst[pst[i1].l].v + q(pst[i1].r, pst[i2].r, v, m + 1, e);
}