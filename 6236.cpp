#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[100'010], l, r, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		l = max(l, arr[i]);
	}
	r = N * l;
	while (l <= r)
	{
		int m = l + r >> 1;
		int cnt = 1, cur = m;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] <= cur) cur -= arr[i];
			else { ++cnt; cur = m - arr[i]; }
		}
		if (cnt <= M)
		{
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << ans;
	
}