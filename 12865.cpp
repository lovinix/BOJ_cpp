#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K, dp[110][100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		int W, V; 
		cin >> W >> V;
		for (int j = 1; j < W; ++j)
			dp[i][j] = dp[i - 1][j];
		for (int j = W; j <= K; ++j)
			dp[i][j] = max(dp[i - 1][j - W] + V, dp[i - 1][j]);
	}
	cout << dp[N][K];
}