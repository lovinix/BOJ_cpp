#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1'000'010;
int Z, N, n, qn, w[sz], p[sz], d[sz], hld[sz], rev[sz], num[sz], node_num, query[sz];
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

int q(int u, int v, int k)
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Z;
	while (Z--)
	{
		cin >> N;
		for (int i = 1; i <= N; ++i) adj[i].clear();
		n = 1, qn = 0;
		for (int i = 0; i < N; ++i)
		{
			char c; int u;
			cin >> c >> u;
			if (c == 'D')
				adj[u].emplace_back(++n);
			else
				query[qn++] = u;
		}
		for (auto& arr : { w,d,p,hld,rev,num })
			fill(arr, arr + n + 1, 0);
		dfs(1);
		dfs2(1);
		int u = 1;
		for (int i = 0; i < qn; ++i)
		{
			int v = query[i];
			if (u == v) cout << u << "\n";
			else cout << (u = q(u, v, 2)) << "\n";
		}
	}
}