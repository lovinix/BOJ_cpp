#include <bits/stdc++.h>
using namespace std;

int arr[1'000'001];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, t;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		int M;
		cin >> M;
		while (M--)
		{
			cin >> t;
			int l = 0, r = N - 1;
			bool f = 0;
			while(l<=r)
			{
				int m = (l + r) >> 1;
				if (arr[m] < t)
					l = m + 1;
				else if (arr[m] > t)
					r = m - 1;
				else
				{
					cout << "1\n";
					f = 1;
					break;
				}
			}
			if (!f) cout << "0\n";
		}
	}
}
