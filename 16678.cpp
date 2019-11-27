#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, arr[100'010];
lli ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	int cnt = 1;
	for (int i = 0; i < N; ++i)
	{
		if (cnt > arr[i]) continue;
		ans += arr[i] - cnt++;
	}
	cout << ans;
}