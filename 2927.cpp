#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

const int MAX = 30'010;
int N, Q, node_num, num[MAX], p[MAX], d[MAX], w[MAX], hld[MAX], seg[4 * MAX], uf[MAX], arr[MAX];
tu qu[MAX*10];
vector<int> adj[MAX];

int f(int u);
void m(int u, int v, int t);
void su(int i, int v, int n = 1, int s = 1, int e = N);
int sq(int l, int r, int n = 1, int s = 1, int e = N);
void dfs(int u);
void dfs2(int u);
int q(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	memset(uf, -1, sizeof uf);
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		string s; int a, b;
		cin >> s >> a >> b;
		qu[i] = { (s[0] == 'b' ? 0 : s[0] == 'p' ? 1 : 2),a,b };
		if (s[0] == 'b') m(a, b, 0);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (uf[i] < 0)
		{
			dfs(i); dfs2(i);
		}
	}
	for (int i = 1; i <= N; ++i)
		su(num[i], arr[i]);
	memset(uf, -1, sizeof uf);
	for (int i = 0; i < Q; ++i)
	{
		auto [F, A, B] = qu[i];
		switch (F)
		{
		case 0:
			if (f(A) == f(B)) { cout << "no\n"; }
			else { cout << "yes\n"; m(A, B, 1); }
			break;
		case 1:
			su(num[A], B - arr[A]);
			arr[A] = B;
			break;
		case 2:
			if (f(A) != f(B)) { cout << "impossible\n"; }
			else { cout << q(A, B) << "\n"; }
		}

	}
}

int f(int u)
{
	return uf[u] < 0 ? u : uf[u] = f(uf[u]);
}

void m(int u, int v, int t)
{
	int x = u, y = v;
	u = f(u); v = f(v);
	if (u == v) return;
	uf[u] += uf[v];
	uf[v] = u;
	if (t == 0)
	{
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
}

void su(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n] += v;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m) su(i, v, n * 2, s, m);
	else su(i, v, n * 2 + 1, m + 1, e);
}

int sq(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return sq(l, r, n * 2, s, m) + sq(l, r, n * 2 + 1, m + 1, e);
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

int q(int u, int v)
{
	int ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret += sq(num[hld[u]], num[u]);
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return ret + sq(num[u], num[v]);
}