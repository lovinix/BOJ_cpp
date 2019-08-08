#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int K, N, arr[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> K >> N;
	lli r = 0;
	for (int i = 0; i < K; ++i)
		cin >> arr[i], r = max(r, (lli)arr[i]);
	lli l = 1, ans = 0;
	while(l<=r)
	{
		lli m = (l + r) >> 1;
		int cnt = 0;
		for(int i=0;i<K;++i)
		{
			cnt += arr[i] / m;
		}
		if (cnt >= N)
			ans = m, l = m + 1;
		else
			r = m - 1;
	}
	cout << ans;
}
