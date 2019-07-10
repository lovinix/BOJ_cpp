#include <bits/stdc++.h>
#define INF 123456
using namespace std;

int N, M;
int arr[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i != j)
				arr[i][j] = INF;
		}
	}
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		arr[u][v] = arr[v][u] = 1;
	}
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int ans = INF, idx = -1;
	for (int i = 1; i <= N; ++i)
	{
		int cur = 0;
		for (int j = 1; j <= N; ++j)
		{
			if (i != j) cur += arr[i][j];
		}
		if (ans > cur) { ans = cur; idx = i; }
	}
	cout << idx;
}