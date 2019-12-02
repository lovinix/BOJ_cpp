#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, dp[51];
vector<int> adj[51];

int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int p; cin >> p;
		if (p != -1) { adj[p].emplace_back(i); }
	}
	dfs(0);
	cout << dp[0];
}

int dfs(int u)
{
	if (dp[u]) return dp[u];
	if (adj[u].size() == 0) return dp[u] = 0;
	for (auto& v : adj[u]) dfs(v);
	sort(adj[u].begin(), adj[u].end(), [](int x, int y) { return dp[x] > dp[y]; });
	for (int i = 1; i <= adj[u].size(); ++i)
	{
		dp[u] = max(dp[u], i + dp[adj[u][i-1]]);
	}
	return dp[u];
}