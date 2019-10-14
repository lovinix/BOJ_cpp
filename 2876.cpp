#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[100'010][2], dp[100'010][6], ans[2];

int recv(int idx, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i][0] >> arr[i][1];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			int cur = recv(i, arr[i][j]);
			if (cur > ans[0]) { ans[0] = cur; ans[1] = arr[i][j]; }
		}
	}
	cout << ans[0] << " " << ans[1];
}

int recv(int idx, int v)
{
	if (idx < 0) return 0;
	if (dp[idx][v]) return dp[idx][v];
	if (arr[idx][0] != v && arr[idx][1] != v) return dp[idx][v] = 0;
	return dp[idx][v] = 1 + recv(idx - 1, v);
}