#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 10'007;
int N, M, H, dp[51][1010], A[51][1010];

int recv(int idx, int h)
{
	if (h == 0) return 1;
	if (idx <= 0 || h < 0) return 0;
	if (dp[idx][h] != -1) return dp[idx][h];
	dp[idx][h] = 0;
	for (int i = 0; i <= h; ++i)
	{
		dp[idx][h] = (dp[idx][h] + recv(idx - 1, h - i) * A[idx][i]) % MOD;
	}
	return dp[idx][h];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> H;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= N; ++i)
	{
		A[i][0] = 1;
		while (1)
		{
			int v; char c;
			cin >> v;
			c = cin.get();
			A[i][v]++;
			if (c == '\n') break;
		}
	}
	cout << recv(N, H);
}