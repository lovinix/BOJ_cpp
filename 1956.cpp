#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
int V, E, dist[410][410];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dist, 0x3f, sizeof dist);
	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		int u, v, d;
		cin >> u >> v >> d;
		dist[u][v] = d;
	}
	for (int k = 1; k <= V; ++k)
	{
		for (int i = 1; i <= V; ++i)
		{
			for (int j = 1; j <= V; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 1; i <= V; ++i)
	{
		for (int j = i + 1; j <= V; ++j)
		{
			ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}
	cout << (ans >= INF ? -1 : ans);
}