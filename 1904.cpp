#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, dp[1'000'010];

int recv(int k);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cout << recv(N);
}

int recv(int k)
{
	if (dp[k]) return dp[k];
	if (k == 1) return 1;
	if (k == 2) return 2;
	return dp[k] = (recv(k - 2) + recv(k - 1))%15746;
}