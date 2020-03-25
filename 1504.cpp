#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

constexpr int INF = 0x1f1f1f1f;
int N, M, dist[1010], vst[1010];
vector<pii> adj[1010];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int dijk(int s, int t)
{
	memset(dist, 0x1f, sizeof dist);
	memset(vst, 0, sizeof vst);
	pq.emplace(0, s);
	dist[s] = 0;
	while (!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if (vst[u]) continue;
		for (auto& [v, w] : adj[u])
		{
			if (dist[v] > d + w)
				pq.emplace(dist[v] = d + w, v);
		}
		vst[u] = 1;
	}
	return dist[t];
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	while (M--)
	{
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].emplace_back(v, d);
		adj[v].emplace_back(u, d);
	}
	int u, v;
	cin >> u >> v;
	int su = dijk(1, u), uv = dijk(u, v), vt = dijk(v, N), sv = dijk(1, v), ut = dijk(u, N);
	int ans = min(su + uv + vt, sv + uv + ut);
	cout << (ans >= INF ? -1 : ans);
}