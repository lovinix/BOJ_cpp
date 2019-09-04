#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100'010;
int N, M, cnt, num[MAX], p[MAX], d[MAX], w[MAX], hld[MAX], seg[4 * MAX], lazy[4 * MAX];
vector<int> adj[MAX];

void dfs(int u);
void dfs2(int u);
void pr(int n, int s, int e);
void su(int l, int r, int v, int n = 1, int s = 1, int e = N);
int sq(int i, int n = 1, int s = 1, int e = N);
void u(int u, int v, int w);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int t; cin >> t;
		if (i == 1) continue;
		adj[t].emplace_back(i);
		p[i] = t;
	}
	dfs(1); dfs2(1);
	while (M--)
	{
		int f, i, x;
		cin >> f;
		switch (f)
		{
		case 1:
			cin >> i >> x;
			u(1, i, x);
			break;
		case 2:
			cin >> i;
			cout << sq(num[i]) << "\n";
		}
	}

}

void dfs(int u)
{
	w[u] = 1;
	for (auto& v : adj[u])
	{
		d[v] = d[u] + 1;
		dfs(v);
		w[u] += w[v];
	}
}

void dfs2(int u)
{
	int cc = -1;
	num[u] = ++cnt;
	for (auto& v : adj[u])
	{
		if (cc == -1 || w[cc] < w[v])
			cc = v;
	}
	if (cc != -1) { hld[cc] = hld[u]; dfs2(cc); }
	for (auto& v : adj[u])
	{
		if (v != cc) { hld[v] = v; dfs2(v); }
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

void su(int l, int r, int v, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l)return;
	if (l <= s && e <= r) { lazy[n] += v; pr(n, s, e); return; }
	int m = s + e >> 1;
	su(l, r, v, n * 2, s, m);
	su(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int sq(int i, int n, int s, int e)
{
	pr(n, s, e);
	if (s == e) return seg[n];
	int m = s + e >> 1;
	if (i <= m) return sq(i, n * 2, s, m);
	else return sq(i, n * 2 + 1, m + 1, e);
}

void u(int u, int v, int w)
{
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		su(num[hld[u]], num[u], w);
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	su(num[u], num[v], w);
}
