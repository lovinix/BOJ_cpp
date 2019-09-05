#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int N, M, n[MAX], f[MAX], ind[MAX], ans, cnt, sz, scc[MAX];
vector<int> adj[MAX];
stack<int> stk;

int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> N >> M;
		while (!stk.empty()) stk.pop();
		memset(n, 0, sizeof n);
		memset(f, 0, sizeof f);
		memset(ind, 0, sizeof ind);
		memset(scc, 0, sizeof scc);
		for (auto& v : adj) v.clear();
		cnt = 0;
		ans = 0;
		sz = 0;
		for (int i = 0; i < M; ++i)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= N; ++i)
		{
			if (n[i] == 0) dfs(i);
		}
		for (int u = 1; u <= N; ++u)
		{
			for (auto& v : adj[u])
			{
				if (scc[u] != scc[v]) ind[scc[v]]++;
			}
		}
		for (int i = 0; i < sz; ++i)
			if (ind[i] == 0) ++ans;
		cout << ans << "\n";
	}
}

int dfs(int u)
{
	n[u] = ++cnt;
	stk.push(u);
	int ret = n[u];
	for (auto& v : adj[u])
	{
		if (n[v] == 0)
		{
			ret = min(ret, dfs(v));
		}
		else if (!f[v])
		{
			ret = min(ret, n[v]);
		}
	}
	if (ret == n[u])
	{
		while (1)
		{
			int c = stk.top();
			stk.pop();
			f[c] = 1;
			scc[c] = sz;
			if (c == u) { sz++; break; }
		}
	}
	return ret;
}