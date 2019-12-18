#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, ans[10'010];
pii arr[10'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i)
	{
		auto& [d, p] = arr[i];
		pii mn = { -1,INT_MAX };
		for (int j = 1; j <= d; ++j)
		{
			if (ans[j] <= mn.second) mn = { j,ans[j] };
		}
		if (mn.second < p) ans[mn.first] = p;
	}
	int sum = 0;
	for (int i = 1; i <= 10000; ++i)
		sum += ans[i];
	cout << sum;
}