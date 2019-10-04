#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, D;
vector<int> arr[200'010], dp[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> D;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int v; cin >> v;
			arr[i].emplace_back(v);
		}
		dp[i].resize(M, INT_MIN);
	}
	for (int j = 0; j < M; ++j) dp[0][j] = 0;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
	{
		for (int r = 1; r <= D; ++r)
		{
			for (int c = -D + 1; c < D; ++c)
			{
				if (r + abs(c) > D) continue;
				int nn = i + r, nc = j + c;
				if (nn >= N || nc < 0 || nc >= M) continue;
				dp[nn][nc] = max(dp[nn][nc], dp[i][j] + arr[i][j] * arr[nn][nc]);
			}
		}
	}
	int ans = INT_MIN;
	for (int j = 0; j < M; ++j)
		ans = max(ans, dp[N - 1][j]);
	cout << ans;
}