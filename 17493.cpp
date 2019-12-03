#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, vst[200'010], p[200'010], dp[200'010][3];
vector<int> adj[200'010];

void dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (vst[i]) continue;
		dfs(i);
		ans += min(dp[i][1], dp[i][2]);
	}
	cout << ans;
}

void dfs(int u)
{
	vst[u] = 1;
	for (auto& v : adj[u])
	{
		if (vst[v]) continue;
		p[v] = u;
		dfs(v);
	}
	dp[u][1] = 1;
	int tmp = 0;
	for (auto& v : adj[u])
	{
		if (v == p[u]) continue;
		dp[u][0] += min(dp[v][1],dp[v][2]);
	}
	dp[u][2] = 200'010;
	for (auto& v : adj[u])
	{
		if (v == p[u]) continue;
		dp[u][2] = min(dp[u][2], dp[u][0] - min(dp[v][1], dp[v][2]) + dp[v][1]);
		dp[u][1] += min({ dp[v][2],dp[v][0],dp[v][1] });
	}
}