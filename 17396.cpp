#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pil = pair<int, lli>;

auto cmp = [](pil& p1, pil& p2) {return p1.second > p2.second; };

int N, M, visit[100'001];
lli dist[100'001];
vector<pil> adj[100'001];
priority_queue<pil, vector<pil>, decltype(cmp)> pq(cmp);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dist, 0x7f, sizeof dist);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> visit[i];
	visit[N - 1] = 0;
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (!visit[v])
			adj[u].emplace_back(v, w);
		if (!visit[u])
			adj[v].emplace_back(u, w);
	}
	dist[0] = 0;
	pq.emplace(0, 0);
	while (!pq.empty())
	{
		auto [u, w] = pq.top();
		pq.pop();
		if (visit[u]) continue;
		for (auto& v : adj[u])
		{
			if (!visit[v.first] && dist[v.first] > v.second + w)
			{
				dist[v.first] = v.second + w;
				pq.emplace(v.first, v.second + w);
			}
		}
		visit[u] = 1;
	}
	cout << (dist[N - 1] > (1LL<<62) ? -1 : dist[N - 1]);
}
