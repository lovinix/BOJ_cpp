#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, n[1010], f[1010], scc[1010], cnt, sccnum, A[1010], rev[1010];
vector<int> adj[1010], stk;

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
		int cnt = 0;
		while (1)
		{
			int c = stk[stk.size() - 1];
			stk.pop_back();
			f[c] = 1;
			scc[c] = sccnum;
			rev[sccnum] = c;
			++cnt;
			if (c == u) { ++sccnum; break; }
		}
		if (cnt > 1) { cout << 0; exit(0); }
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int c; cin >> c;
		for (int j = 0; j < c; ++j)
			cin >> A[j];
		for (int j = 0; j < c - 1; ++j)
		{
			adj[A[j]].emplace_back(A[j + 1]);
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!n[i]) dfs(i);
	}
	for (int i = sccnum - 1; i >= 0; --i)
		cout << rev[i] << "\n";
}