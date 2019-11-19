#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli MOD = 1e9 + 7;
lli H, x, dp[1'000'010], ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	dp[0] = 1;
	cin >> H >> x;
	for (int i = 1; i <= H; ++i)
		dp[i] = (dp[i - 1] * x) % MOD;
	for (int i = 1; i <= H; ++i)
	{
		lli v; cin >> v;
		ans = (ans + v * dp[i]) % MOD;
	}
	cout << ans;
}