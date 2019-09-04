#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100'010;
int N, M, arr[MAX];
vector<int> adj[MAX];

void dfs(int u, int cur);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int p; cin >> p;
		if (i == 1) continue;
		adj[p].emplace_back(i);
	}
	while (M--)
	{
		int u, w;
		cin >> u >> w;
		arr[u] += w;
	}
	dfs(1, 0);
	for (int i = 1; i <= N; ++i)
		cout << arr[i] << " ";
}

void dfs(int u, int cur)
{
	arr[u] += cur;
	for (auto& v : adj[u])
		dfs(v, arr[u]);
}