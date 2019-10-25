#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[30'010], ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < N; ++i)
	{
		int cnt = 0, cur = arr[i];
		for (int j = i + 1; j < N && arr[j] < cur; ++j) 
			++cnt;
		ans = max(ans, cnt);
	}
	cout << ans;
}