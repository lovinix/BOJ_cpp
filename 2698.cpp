#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N, K;
lli dp[1001][1001][2];

lli recv(int n, int k, int i);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		cout << recv(N, K, 0) + recv(N, K, 1) << "\n";
	}
}

lli recv(int n, int k, int i)
{
	if (n <= k) return 0;
	if (n < 1) return 0;
	if (dp[n][k][i]) return dp[n][k][i];
	if (i)
		return dp[n][k][i] = recv(n - 1, k - 1, 1) + recv(n - 1, k, 0);
	else
		return dp[n][k][i] = recv(n - 1, k, 0) + recv(n - 1, k, 1);
}