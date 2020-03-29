#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 0x3f3f3f3f;
int N, K, S, dist[410][410];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	memset(dist, 0x3f, sizeof dist);
	for (int i = 0; i < K; ++i)
	{
		int u, v;
		cin >> u >> v;
		dist[u][v] = 1;
	}
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	cin >> S;
	while (S--)
	{
		int u, v;
		cin >> u >> v;
		if (dist[u][v] < INF) cout << "-1\n";
		else if (dist[v][u] < INF) cout << "1\n";
		else cout << "0\n";
	}
}