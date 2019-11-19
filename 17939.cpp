#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[100'010], mx[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	int m = arr[N - 1];
	for (int i = N - 1; i >= 0; --i)
	{
		m = max(m, arr[i]);
		mx[i] = m;
	}
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		if (mx[i] <= arr[i]) continue;
		ans += mx[i] - arr[i];
	}
	cout << ans;
}