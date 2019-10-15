#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'000;
int N, tmp[2'000'100];
auto dp = &tmp[1'000'010];

int recv(int i);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	dp[1] = 1;
	cin >> N;
	int ans = recv(N);
	cout << (ans > 0 ? 1 : ans == 0 ? 0 : -1) << "\n" << abs(ans);
}

int recv(int i)
{
	if (i == 0) return 0;
	if (dp[i]) return dp[i];
	if (i > 0) return dp[i] = (recv(i - 1) + recv(i - 2)) % MOD;
	else return dp[i] = (recv(i + 2) - recv(i + 1)) % MOD;
}