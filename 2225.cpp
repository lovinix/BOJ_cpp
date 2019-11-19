#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MOD = 1'000'000'000;
int N, K;
int dp[210][210];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i <= K; ++i) dp[0][i] = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			for (int k = 0; k <= i; ++k)
			{
				dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % MOD;
			}
		}
	}
	cout << dp[N][K];
}