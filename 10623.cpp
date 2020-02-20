#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

constexpr int sz = 100'010;
int N, w[sz], num[sz], hld[sz], d[sz], p[sz], node_num;
vector<int> adj[sz], tr;
queue<int> qu;

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
		ret += num[u] - num[hld[u]] + 1;
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return ret + num[v] - num[u];
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 2; i <= N; ++i)
	{
		int p; cin >> p;
		adj[p].emplace_back(i);
	}
	dfs(1);
	dfs2(1);
	lli ans = 0;
	qu.emplace(1);
	while (!qu.empty())
	{
		auto cur = qu.front();
		tr.emplace_back(cur);
		qu.pop();
		for (auto& nxt : adj[cur])
			qu.emplace(nxt);
	}
	for (int i = 0; i < tr.size() - 1; ++i)
		ans += q(tr[i], tr[i + 1]);
	cout << ans;
}