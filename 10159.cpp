#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, dist[110][110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	memset(dist, 0x3f, sizeof dist);
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		dist[v][u] = 1;
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
	for (int i = 1; i <= N; ++i)
	{
		int ans = 0;
		for (int j = 1; j <= N; ++j)
		{
			if (i == j) continue;
			ans += dist[i][j] == 0x3f3f3f3f && dist[j][i] == 0x3f3f3f3f;
		}
		cout << ans << '\n';
	}
}