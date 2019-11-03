#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[2000][2000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> arr[i][j];
	for (; N != 1; N /= 2)
	{
		for (int i = 1; i <= N / 2; ++i)
		{
			for (int j = 1; j <= N / 2; ++j)
			{
				int r = (i - 1) * 2 + 1;
				int c = (j - 1) * 2 + 1;
				vector<int> tmp = { arr[r][c],arr[r + 1][c],arr[r][c + 1],arr[r + 1][c + 1] };
				sort(tmp.begin(), tmp.end());
				arr[i][j] = tmp[2];
			}
		}
	}
	cout << arr[1][1];
}