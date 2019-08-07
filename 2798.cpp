#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i=0;i<N;++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int ans = 0;
	for(int i=0;i<N;++i)
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			int c = arr[i] + arr[j];
			if (c >= M) break;
			int l = j + 1, r = N - 1;
			while(l<=r)
			{
				int m = (l + r) >> 1;
				if (arr[m] + c > M)
					r = m - 1;
				else
					ans = max(ans,arr[m]+c), l = m + 1;
			}
		}
	}
	cout << ans;;
}
