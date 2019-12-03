#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, dp[100'010][21], INF=1e7;
vector<int> adj[100'010];

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
	int ans = INF;
	for (int i = 1; i <= 20; ++i)
		ans = min(ans, dp[1][i]);
	cout << ans;
}

void dfs(int u, int p)
{
	for (auto& v : adj[u])
	{
		if (v != p) dfs(v, u);
	}
	for (auto& v : adj[u])
	{
		if (v == p) continue;
		int mn = INF, idx = -1;
		for (int i = 1; i <= 20; ++i)
		{
			if (mn > dp[v][i]) { mn = dp[v][i]; idx = i; }
		}
		int mn2 = INF, idx2 = -1;
		for (int i = 1; i <= 20; ++i)
		{
			if (mn2 > dp[v][i] && i != idx) { mn2 = dp[v][i]; idx2 = i; }
		}
		for (int i = 1; i <= 20; ++i)
		{
			if (i != idx) dp[u][i] += mn; 
			else dp[u][i] += mn2;
			if (dp[u][i] > INF) dp[u][i] = INF;
		}
	}
	for (int i = 1; i <= 20; ++i)
		dp[u][i] += i;
}