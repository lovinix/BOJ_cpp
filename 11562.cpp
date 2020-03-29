#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 0x3f3f3f3f;
int N, M, K, dist[260][260];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dist, 0x3f, sizeof dist);
	cin >> N >> M;
	for (int i = 0; i <= N; ++i) dist[i][i] = 0;
	for (int i = 0; i < M; ++i)
	{
		int u, v, b;
		cin >> u >> v >> b;
		dist[u][v] = 1;
		dist[v][u] = b ? 1 : 100'000;
	}
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	cin >> K;
	while (K--)
	{
		int s, e;
		cin >> s >> e;
		cout << dist[s][e] / 100'000 << "\n";
	}
}