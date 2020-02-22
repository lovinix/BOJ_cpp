#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, vst[1010];
vector<int> adj[1010];

void dfs(int u)
{
	vst[u] = 1;
	for (auto& v : adj[u])
	{
		if (!vst[v]) dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	while (M--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (!vst[i]) { ++ans; dfs(i); }
	}
	cout << ans;
}