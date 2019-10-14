#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, cnt[] = { -123456,-123456,1,7,4,8,14,11 }, dp[1'000'010];

int recv(int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	memset(dp, -1, sizeof dp);
	cout << recv(N);
}

int recv(int v)
{
	if (v <= 7) return cnt[v];
	if (dp[v] != -1) return dp[v];
	int ret = 0;
	for (int i = 2; i <= 7; ++i)
		ret = max(ret, recv(i)+recv(v-i));
	return dp[v] = ret;
}