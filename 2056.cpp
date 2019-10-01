#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, arr[10'010], ind[10'010], dp[10'010], ans;
vector<int> adj[10'010];
queue<pii> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		int t; cin >> t;
		ind[i] += t;
		if (!t) q.emplace(i,arr[i]);
		while (t--)
		{
			int v; cin >> v;
			adj[v].emplace_back(i);
		}
	}
	while (!q.empty())
	{
		auto [u, d] = q.front();
		ans = max(ans, d);
		q.pop();
		for (auto& v : adj[u])
		{
			dp[v] = max(dp[v], arr[v] + d);
			if (!--ind[v]) q.emplace( v,dp[v] );
		}
	}
	cout << ans;

}