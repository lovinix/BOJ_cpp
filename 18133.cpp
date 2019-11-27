#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, M, n[100'010], f[100'010], sccnum, cnt, in[100'010], scc[100'010];
vector<int> adj[100'010], stk, lst[100'010];

int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i <= N; ++i)
			adj[i].clear(), lst[i].clear(), scc[i] = n[i] = f[i] = in[i] = 0;
		stk.clear();
		sccnum = cnt = 0;
		for (int i = 0; i < M; ++i)
		{
			int u, v;
			cin >> u >> v;
			adj[u].emplace_back(v);
		}
		for (int i = 1; i <= N; ++i)
			if (!n[i]) dfs(i);
		int ans = 0;
		for (int i = 0; i < sccnum; ++i)
		{
			if (!in[i]) ++ans;
		}
		cout << ans << '\n';
	}
}

int dfs(int u)
{
	n[u] = ++cnt;
	int ret = n[u];
	stk.emplace_back(u);
	for (auto& v : adj[u])
	{
		if (!n[v]) ret = min(ret, dfs(v));
		else if (!f[v]) ret = min(ret, n[v]);
	}
	if (ret == n[u])
	{
		while (1)
		{
			int c = stk[stk.size() - 1];
			stk.pop_back();
			f[c] = 1;
			scc[c] = sccnum;
			lst[sccnum].emplace_back(c);
			if (c == u) { ++sccnum; break; }
		}
		for (auto& v : lst[sccnum - 1])
			for (auto& c : adj[v])
				if (scc[c] != scc[v]) in[scc[c]]++;
	}
	return ret;
}