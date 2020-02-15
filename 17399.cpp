#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 100'010;
int N, Q, w[sz], num[sz], p[sz], hld[sz], d[sz], rev[sz], node_num;
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

int dist(int u, int v)
{
	int ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret += d[u] - d[hld[u]] + 1;
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return ret + d[v] - d[u];
}

int par(int u, int l)
{
	while (l > d[u] - d[hld[u]])
	{
		l -= d[u] - d[hld[u]] + 1;
		u = p[hld[u]];
	}
	return rev[num[u] - l];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1);
	dfs2(1);
	cin >> Q;
	while (Q--)
	{
		int A[3];
		for (auto& i : A) cin >> i;
		swap(A[0], *min_element(A, A + 3, [](int& u, int& v) {return d[u] > d[v]; }));
		int d = dist(A[0], A[1]);
		if (int d2 = dist(A[0], A[2]); d2 > d) { swap(d, d2); swap(A[1], A[2]); }
		if (d & 1) { cout << "-1\n"; continue; }
		int x = par(A[0], d / 2);
		if (dist(A[2], x) == d / 2) cout << x << "\n";
		else cout << "-1\n";
	}
}