#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100'010;
int N, M, node_num, num[MAX], rev[MAX], p[MAX];
int w[MAX], d[MAX], hld[MAX], seg[4 * MAX];
bool st[MAX];
vector<int> adj[MAX];

void dfs(int u);
void dfs2(int u);
void su(int i, int n = 1, int s = 1, int e = N);
int sq(int l, int r, int n = 1, int s = 1, int e = N);
int q(int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fill(seg, seg + 4 * MAX, MAX);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1); dfs2(1);
	cin >> M;
	while (M--)
	{
		int f, i, v;
		cin >> f;
		if (f == 1)
		{
			cin >> i;
			su(num[i]);
		}
		else
		{
			cin >> v;
			cout << q(v) << "\n";
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
		if (p[v] == u && (cc == -1 || w[cc] < w[v]))
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

void su(int i, int n, int s, int e)
{
	if (s > i || e < i) return;
	if (s == e) { st[i] ^= 1; seg[n] = st[i] ? i : MAX; return; }
	int m = s + e >> 1;
	if (i <= m) su(i, n * 2, s, m);
	else su(i, n * 2 + 1, m + 1, e);
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

int sq(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return MAX;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return min(sq(l, r, n * 2, s, m), sq(l, r, n * 2 + 1, m + 1, e));
}

int q(int v)
{
	int ret = MAX;
	while (hld[v] != hld[1])
	{
		ret = min(ret, sq(num[hld[v]], num[v]));
		v = p[hld[v]];
	}
	ret = min(ret, sq(1, num[v]));
	return ret == MAX ? -1 : rev[ret];
}