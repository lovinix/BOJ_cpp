#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int>;

int N;
lli arr[5010], cur=LLONG_MAX;
tu ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			lli tmp = arr[i] + arr[j];
			int idx = upper_bound(arr + j + 1, arr + N, -tmp) - arr;
			if (idx != N && abs(tmp + arr[idx]) < cur) { cur = abs(tmp + arr[idx]); ans = { i,j,idx }; }
			if (idx-- == j + 1) continue;
			if (abs(tmp + arr[idx]) < cur) { cur = abs(tmp + arr[idx]); ans = { i,j,idx }; }
		}
	}
	auto& [i, j, k] = ans;
	int tmp[] = { arr[i],arr[j],arr[k] };
	sort(tmp, tmp + 3);
	cout << tmp[0] << " " << tmp[1] << " " << tmp[2];
}