#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int ans, cur;
pii arr[11];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 11; ++i)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + 11);
	for (int i = 0; i < 11; ++i)
	{
		cur += arr[i].first;
		ans += cur + 20 * arr[i].second;
	}
	cout << ans;
}