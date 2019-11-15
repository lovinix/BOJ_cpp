#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pil = pair<int, lli>;

int N, M, K, arr[100'010], visit[100'010];
lli dist[100'010];
vector<pil> adj[100'010];
auto cmp = [](pil& p1, pil& p2) {return p1.second > p2.second; };
priority_queue<pil, vector<pil>, decltype(cmp)> pq(cmp);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[v].emplace_back(u, c);
	}
	for (int i = 0; i < K; ++i)
	{
		int u; cin >> u;
		adj[0].emplace_back(u, 0);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;
	pq.emplace(0, 0);
	while (!pq.empty())
	{
		auto [u, c] = pq.top();
		pq.pop();
		if (visit[u]) continue;
		for (auto& [v, w] : adj[u])
		{
			if (dist[v] <= c + w) continue;
			dist[v] = c + w;
			pq.emplace(v, dist[v]);
		}
		visit[u] = 1;
	}
	int idx = -1; lli d = -1;
	for (int i = 1; i <= N; ++i)
	{
		if (dist[i] > d) { d = dist[i]; idx = i; }
	}
	cout << idx << "\n" << d;
}