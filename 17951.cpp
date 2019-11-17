#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K, arr[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	int l = 0, r = 3'000'000, ans;
	while (l <= r)
	{
		int m = l + r >> 1;
		int cnt = 0, sum = 0;
		for (int i = 0; i < N; ++i)
		{
			sum += arr[i];
			if (sum >= m) { ++cnt; sum = 0; }
		}
		if (cnt >= K) { ans = m; l = m + 1; }
		else r = m - 1;
	}
	cout << ans;
}