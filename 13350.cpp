#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, D, C, F, U, l, r;
int dp[3000][3000];
vector<pii> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dp, 0x3f, sizeof dp);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> D >> C >> F >> U;
		if (C + U <= F) { r += D; continue; }
		if (C > F + U) { l += D; continue; }
		v.emplace_back((F - C + U) / 2 + 1, D);
	}
	int sum = 0;
	for (auto& [u, d] : v)
		sum += d;
	if (l + sum <= r) { cout << "impossible"; return 0; }
	for (int i = 0; i <= v.size(); ++i)
		dp[i][0] = 0;
	for (int i = 1; i <= v.size(); ++i)
	{
		auto& [u, d] = v[i - 1];
		for (int j = 1; j <= sum; ++j)
		{
			dp[i][j] = min({ dp[i - 1][j], dp[i - 1][max(j-d,0)] + u });
		}
	}
	if (l > r + sum) { cout << 0; return 0; }
	int dif = (r - l + sum) / 2 + 1;
	int ans = INT_MAX;
	for (int i = dif; i <= sum; ++i)
		ans = min(ans, dp[v.size()][i]);
	cout << ans;
}