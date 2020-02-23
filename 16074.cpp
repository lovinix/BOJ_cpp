#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

constexpr int sz = 300'010;
int N, M, Q, A[510][510], dn[] = { 1,0 }, dm[] = { 0,1 }, uf[sz];
int w[sz], p[sz], d[sz], hld[sz], num[sz], node_num, seg[4 * sz];
vector<int> adj[sz];
vector<tu> E;

int f(int u)
{
	return uf[u] < 0 ? u : uf[u] = f(uf[u]);
}

void m(int u, int v)
{
	int _u = f(u), _v = f(v);
	if (_u == _v) return;
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
	uf[_u] += uf[_v];
	uf[_v] = _u;
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

void su(int i, int v, int n = 1, int s = 1, int e = sz)
{
	if (s > i || e < i) return;
	if (s == e) { seg[n] = v; return; }
	int m = s + e >> 1;
	su(i, v, n * 2, s, m);
	su(i, v, n * 2 + 1, m + 1, e);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int sq(int l, int r, int n = 1, int s = 1, int e = sz)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return max(sq(l, r, n * 2, s, m), sq(l, r, n * 2 + 1, m + 1, e));
}

int q(int u, int v)
{
	int ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret = max(ret, sq(num[hld[u]], num[u]));
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return max(ret, sq(num[u], num[v]));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(uf, -1, sizeof uf);
	cin >> N >> M >> Q;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				int nn = i + dn[k], nm = j + dm[k];
				if (nn < 0 || nn >= N || nm < 0 || nm >= M) continue;
				E.emplace_back(max(A[i][j], A[nn][nm]), i * M + j, nn * M + nm);
			}
		}
	}
	sort(E.begin(), E.end());
	for (auto& [h, u, v] : E)
		m(u, v);
	dfs(0);
	dfs2(0);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			su(num[i * M + j], A[i][j]);
		}
	}
	while (Q--)
	{
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;
		--X1, --Y1, --X2, --Y2;
		cout << q(X1 * M + Y1, X2 * M + Y2) << "\n";
	}
}