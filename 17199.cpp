#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, visit[110], cnt;
vector<int> adj[110];

int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[v].emplace_back(u);
	}
	for (int i = 1; i <= N; ++i)
	{
		memset(visit, 0, sizeof visit);
		cnt = dfs(i);
		if (cnt == N) { cout << i; return 0; }
	}
	cout << -1;
}

int dfs(int u)
{
	int ret = visit[u] = 1;
	for (auto& v : adj[u])
	{
		if (visit[v]) continue;
		ret += dfs(v);
	}
	return ret;
}