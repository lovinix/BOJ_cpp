#include <bits/stdc++.h>
using namespace std;

int N, C, arr[200'001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	int l = 1, r = arr[N - 1], ans = 0;
	while(l<=r)
	{
		int m = (l + r) >> 1;
		int cnt = 0, dif = 0;
		for(int i=0;i<N-1;++i)
		{
			if (arr[i + 1] - arr[i] + dif >= m)
				++cnt, dif = 0;
			else
				dif += arr[i + 1] - arr[i];
		}
		if (cnt+1 >= C)
			ans = m, l = m + 1;
		else
			r = m - 1;
	}
	cout << ans;
}
