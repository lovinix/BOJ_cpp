#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
double A[10'010], dp[10'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	dp[0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
		dp[i] = dp[i - 1] >= 1 ? dp[i - 1] * A[i] : A[i];
	}
	cout << fixed << setprecision(3) << *max_element(dp + 1, dp + N + 1);
}