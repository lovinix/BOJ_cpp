#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, A[1010], dp[1010];

int recv(int idx)
{
	if (dp[idx]) return dp[idx];
	dp[idx] = 1;
	for (int i = idx + 1; i <= N; ++i)
	{
		if (A[i] > A[idx])
			dp[idx] = max(dp[idx], recv(i) + 1);
	}
	return dp[idx];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		ans = max(ans, recv(i));
	cout << ans << '\n';
	for (int i = 1; i <= N; ++i)
	{
		if (dp[i] == ans)
		{
			cout << A[i] << " ";
			--ans;
		}
	}
}