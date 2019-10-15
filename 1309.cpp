#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MOD = 9901;
int N, dp[100'010], psum[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	dp[0] = 1; psum[0] = 1;
	dp[1] = 2; psum[1] = 3;
	for (int i = 2; i <= N; ++i)
	{
		dp[i] = (dp[i] + psum[i - 2] * 2) % MOD;
		dp[i] = (dp[i] + dp[i - 1]) % MOD;
		psum[i] = (psum[i - 1] + dp[i]) % MOD;
	}
	cout << psum[N];
}