#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, dp[100'010][20], arr[100'010][20];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cin >> arr[j][i];
	}
	for (int i = 1; i <= M; ++i)
		dp[1][i] = arr[1][i];
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			for (int k = 1; k <= M; ++k)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + (j == k ? arr[i][j] / 2 : arr[i][j]));
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= M; ++i)
		ans = max(ans, dp[N][i]);
	cout << ans;
}