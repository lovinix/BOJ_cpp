#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N, dp[200'010], MOD = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= 191229; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << dp[N] << "\n";
	}
}