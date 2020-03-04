#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

constexpr int sz = 100'010;
int N, Q, w[sz], p[sz], d[sz], hld[sz], num[sz], node_num, PS[sz];
vector<int> adj[sz];
tu E[100'010];

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
		ret += PS[num[u]] - PS[num[hld[u]] - 1];
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return ret + PS[num[v]] - PS[num[u]];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 1; i < N; ++i)
	{
		auto& [u, v, c] = E[i];
		cin >> u >> v >> c;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1);
	dfs2(1);
	sort(E + 1, E + N, [](tu& t1, tu& t2)
		{
			auto& [u1, v1, c1] = t1;
			auto& [u2, v2, c2] = t2;
			return max(num[u1], num[v1]) < max(num[u2], num[v2]);
		}
	);
	for (int i = 1; i < N; ++i)
	{
		auto& [u, v, c] = E[i];
		PS[max(num[u], num[v])] = PS[max(num[u], num[v]) - 1] + c;
	}
	while (Q--)
	{
		int u, v;
		cin >> u >> v;
		cout << q(u, v) << "\n";
	}
}