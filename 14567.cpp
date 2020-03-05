#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, cnt[1010], ans[1010];
vector<int> adj[1010];
queue<pii> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		cnt[v]++;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (cnt[i] == 0) q.emplace(i, 1);
	}
	while (!q.empty())
	{
		auto& [u, d] = q.front();
		q.pop();
		ans[u] = max(ans[u], d);
		for (auto& v : adj[u])
		{
			cnt[v]--;
			if (cnt[v] == 0) q.emplace(v, d + 1);
		}
	}
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << " ";
}