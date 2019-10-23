#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[10'010], dp[10'010][2];
vector<int> adj[10'010];

int recv(int u, int f, int p);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	memset(dp, -1, sizeof dp);
	cout << max(recv(1, 0, 0), recv(1, 1, 0));
}

int recv(int u, int f, int p)
{
	if (dp[u][f] != -1) return dp[u][f];
	dp[u][0] = 0; dp[u][1] = arr[u];
	for (auto& v : adj[u])
	{
		if (v == p) continue;
		dp[u][0] += max(recv(v, 0, u), recv(v, 1, u));
		dp[u][1] += recv(v, 0, u);
	}
	return dp[u][f];
}