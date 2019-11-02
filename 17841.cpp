#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MOD = 1e9 + 7;
int N;
char a[6] = { ' ','U','N','I','S','T' };
lli dp[100'010][6];
string arr[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		arr[i] += '!';
	}
	for (int i = 0; i <= N; ++i)
		dp[i][0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		int idx = 6, cur = 0;
		for (int k = 1; k < 6; ++k)
		{
			if (arr[i][0] == a[k]) { idx = k; break; }
		}
		if (idx == 6) goto next;
		cur = idx;
		for (int j = 0;;)
		{
			dp[i][cur] = (dp[i][cur] + dp[i - 1][idx - 1]) % MOD;
			if (cur < 5 && j + 1 < arr[i].length() && arr[i][j + 1] == a[cur + 1])
				++j, ++cur;
			else break;
		}
	next:;
		for (int j = 1; j <= 5; ++j) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
	}
	cout << dp[N][5];
}