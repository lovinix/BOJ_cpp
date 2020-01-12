#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, dp[1010][1010][3][3], c[1010][3];

int recv(int l, int r, int cl, int cr);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> c[i][j];
	if (N == 1) { cout << min({ c[1][0],c[1][1],c[1][2] }); return 0; }
	int ans = 1e9;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == j) continue;
			ans = min(ans, recv(1, N, i, j));
		}
	}
	cout << ans;
}

int recv(int l, int r, int cl, int cr)
{
	if (l > r) return 0;
	if (dp[l][r][cl][cr]) return dp[l][r][cl][cr];
	if (l == r)  return dp[l][r][cl][cr] = cl == cr ? c[l][cl] : INF;
	if (r - l == 1)
	{
		if (cl == cr) return INF;
		return dp[l][r][cl][cr] = c[l][cl] + c[r][cr];
	}
	int ret = 1e9;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (cl == i || cr == j) continue;
			ret = min(ret, recv(l + 1, r - 1, i, j));
		}
	}
	return dp[l][r][cl][cr] = ret + c[l][cl] + c[r][cr];
}