#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, dp[11];

int recv(int i);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cout << recv(N);
}

int recv(int i)
{
	if (dp[i]) return dp[i];
	int& ret = dp[i];
	for (int k = 1; k <= i / 2; ++k)
		ret = max(ret, k * (i - k) + recv(k) + recv(i - k));
	return ret;
}