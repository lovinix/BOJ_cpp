#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, dp[100'010];

int recv(int i);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	dp[1] = 1;
	cout << recv(N);
}

int recv(int i)
{
	if (i == 0) return 0;
	if (dp[i]) return dp[i];
	if ((int)sqrt(i) * (int)sqrt(i) == i)
		return dp[i] = 1;
	int ret = INT_MAX;
	for (int v = 1; v * v <= i; ++v)
		ret = min(ret, 1 + recv(i - v * v));
	return dp[i] = ret;
}