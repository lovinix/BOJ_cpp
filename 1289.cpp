#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pll = pair<lli, lli>;

int N, MOD = 1e9+7;
lli dp[100'010], ans;
vector<pll> adj[100'010];

lli dfs(int u, int p);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}
	dfs(1, 1);
	cout << ans;
}

lli dfs(int u, int p)
{
	vector<lli> vt;
	lli cur = 0;
	for (auto& [v, w] : adj[u])
	{
		if (v == p) continue;
		dp[u] = (dp[u] + w * dfs(v, u)) % MOD;
		vt.emplace_back((w * dp[v]) % MOD);
	}

	for (auto& v : vt)
	{
		cur = (cur + ((dp[u] - v + MOD) % MOD) * v) % MOD;
	}
	cur = (cur * 500'000'004) % MOD;
	ans = (ans + cur + dp[u]) % MOD;
	return dp[u] = (dp[u] + 1) % MOD;
}