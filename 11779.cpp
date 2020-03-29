#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, dist[1010], vst[1010], prv[1010];
vector<pii> adj[1010];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].emplace_back(v, d);
	}
	int s, t;
	cin >> s >> t;
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	pq.emplace(0, s);
	while (!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if (vst[u]) continue;
		for (auto& [v, w] : adj[u])
		{
			if (dist[v] > w + d)
			{
				pq.emplace(dist[v] = w + d, v);
				prv[v] = u;
			}
		}
		vst[u] = 1;
	}
	vector<int> ans;
	for (int v = t; v != s; v = prv[v]) ans.emplace_back(v);
	cout << dist[t] << "\n";
	cout << ans.size() + 1 << "\n";
	cout << s << " ";
	while (ans.size()) { cout << ans.back() << " "; ans.pop_back(); }
}