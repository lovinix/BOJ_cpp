#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool visit[100'001];
int V, a, ans;
vector<pii> adj[100'001];

void dfs(int u, int d = 0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> V;
	for (int i = 1; i < V; ++i)
	{
		int u, v, d;
		cin >> u;
		while (1)
		{
			cin >> v;
			if (v == -1) break;
			cin >> d;
			adj[u].emplace_back(v, d);
			adj[v].emplace_back(u, d);
		}
	}
	dfs(1);
	memset(visit, 0, sizeof visit);
	dfs(a);
	cout << ans;
}

void dfs(int u, int d)
{
	visit[u] = 1;
	if (d > ans) a = u, ans = d;
	for (auto& v : adj[u])
		if (!visit[v.first]) dfs(v.first, v.second + d);
}