#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, c[200'010];
lli dp[200'010][2];
vector<int> adj[200'010];

void dfs(int u);

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
	for (int i = 1; i <= N; ++i)
		cin >> c[i];
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
}

void dfs(int u)
{
	if (adj[u].size() == 0) return;
	for (auto& v : adj[u])
		dfs(v);
	for (auto& v : adj[u])
		dp[u][0] += max(dp[v][0], dp[v][1]);
	for (auto& v : adj[u])
		dp[u][1] = max(dp[u][1], (dp[u][0] - max(dp[v][0], dp[v][1]) + c[u] * c[v] + dp[v][0]));
}