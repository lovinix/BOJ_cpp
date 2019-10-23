#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[10'010], dp[10'010][2];
vector<int> adj[10'010], ans;

int recv(int u, int f, int p);
void dfs(int u, int f, int p);

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
	int mx = 0;
	memset(dp, -1, sizeof dp);
	mx = max(recv(1, 1, 0), recv(1, 0, 0));
	cout << mx << "\n";
	if (recv(1, 1, 0) == mx)
		dfs(1, 1, 0);
	else
		dfs(1, 0, 0);
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
		cout << i << " ";
}

int recv(int u, int f, int p)
{
	if (dp[u][f] != -1) return dp[u][f];
	dp[u][0] = 0; dp[u][1] = arr[u];
	for (auto& v : adj[u])
	{
		if (v == p) continue;
		dp[u][0] += max(recv(v, 1, u), recv(v, 0, u));
		dp[u][1] += recv(v, 0, u);
	}
	return dp[u][f];
}

void dfs(int u, int f, int p)
{
	if (f == 1)
	{
		ans.emplace_back(u);
		for (auto& v : adj[u])
			if (v == p) continue;
			else dfs(v, 0, u);
	}
	else
	{
		for (auto& v : adj[u])
		{
			if (v == p) continue;
			if (dp[v][1] > dp[v][0])
				dfs(v, 1, u);
			else
				dfs(v, 0, u);
		}
	}
}