#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Edge
{
	int u, v, w, idx;
	bool operator<(Edge& e) { return w < e.w; }
};


char buf[10'000'010];
int idx;

inline int readInt()
{
	int ret = 0;
	while (buf[idx] != '\n' && buf[idx] != ' ' && buf[idx] != 0) ret = ret * 10 + buf[idx++] - '0';
	while (buf[idx] == '\n' || buf[idx] == ' ') ++idx;
	return ret;
}


int N, M, pa[200'010], seg[4*200'010], num[200'010], hld[200'010], w[200'010], p[200'010];
int d[200'010], node_num, cc, flag[200'010];
lli mst, ans[200'010];
Edge edge[200'010];
vector<int> adj[200'010];

int f(int u);
void m(int u, int v, int w, int idx);
void dfs(int u);
void dfs2(int u);
void su(int i, int v, int n = 1, int s = 1, int e = N);
int sq(int l, int r, int n = 1, int s = 1, int e = N);
int q(int u, int v);

int main()
{
	memset(pa, -1, sizeof pa);
	fread(buf, 1, sizeof buf, stdin);
	N = readInt();
	M = readInt();
	for (int i = 0; i < M; ++i)
	{
		int u = readInt(), v = readInt(), w = readInt();
		edge[i] = { u,v,w,i };
	}
	sort(edge, edge + M);
	for (int i = 0; i < M; ++i)
		m(edge[i].u, edge[i].v, edge[i].w, edge[i].idx);
	dfs(1); dfs2(1);
	for (int i = 0; i < M; ++i)
	{
		auto& [u, v, w, idx] = edge[i];
		if (flag[idx]) su((d[u] > d[v] ? num[u] : num[v]), w);
	}
	for (int i = 0; i < M; ++i)
	{
		auto& [u, v, w, idx] = edge[i];
		if (flag[idx]) ans[idx] = mst;
		else
			ans[idx] = mst - q(u, v) + w;
	}
	for (int i = 0; i < M; ++i)
		printf("%lld\n", ans[i]);
}

int f(int u)
{
	return pa[u] < 0 ? u : pa[u] = f(pa[u]);
}

void m(int u, int v, int w, int idx)
{
	int u1 = u, v1 = v;
	u = f(u); v = f(v);
	if (u == v) return;
	adj[u1].emplace_back(v1);
	adj[v1].emplace_back(u1);
	flag[idx] = 1;
	pa[u] += pa[v];
	pa[v] = u;
	mst += w;
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

void su(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	if (s == e) { seg[n] = v; return; }
	int m = s + e >> 1;
	su(i, v, n * 2, s, m);
	su(i, v, n * 2 + 1, m + 1, e);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int sq(int l, int r, int n, int s, int e)
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
	return max(ret, sq(num[u] + 1, num[v]));
}

