#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, dp[1'000'010][2];
vector<int> adj[1'000'010];

void dfs(int u, int p);

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
	dfs(1, 1);
	cout << min(dp[1][0], dp[1][1]);
}

void dfs(int u, int p)
{
	for (auto& v : adj[u])
	{
		if (v != p) dfs(v, u);
	}
	dp[u][1] = 1;
	for (auto& v : adj[u])
	{
		if (v == p) continue;
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][0], dp[v][1]);
	}
}