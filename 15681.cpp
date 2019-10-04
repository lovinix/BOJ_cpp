#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, R, Q, num[100'010], cnt, r[100'010];
vector<int> adj[100'010];

void dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> R >> Q;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(R);
	while (Q--)
	{
		int u; cin >> u;
		cout << r[u] - num[u] + 1 << "\n";
	}
}

void dfs(int u)
{
	num[u] = ++cnt;
	for (auto& v : adj[u])
		if (!num[v]) dfs(v);
	r[u] = cnt;
}