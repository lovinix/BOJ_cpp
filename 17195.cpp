#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
string arr[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < N; ++i)
	{
		if (arr[i][0] == arr[0][0]) continue;
		for (int j = 0; j < N; ++j)
			arr[i][j] = arr[i][j] == 'R' ? 'L' : 'R';
	}
	for (int j = 0; j < N; ++j)
	{
		if (arr[0][j] == arr[0][0]) continue;
		for (int i = 0; i < N; ++i)
			arr[i][j] = arr[i][j] == 'R' ? 'L' : 'R';
	}
	int cnt = 0, r, c;
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			if (arr[i][j] != arr[0][0]) { ++cnt; r = i, c = j; }
		}
	}
	if (cnt == N * N - N - N + 1) { cout << "1 1"; return 0; }
	if (cnt == 1) { cout << r + 1 << " " << c + 1; return 0; }
	if (cnt == N - 1)
	{
		for (int i = 1; i < N; ++i)
		{
			if (arr[i][c] == arr[0][0]) goto next;
		}
		cout << 1 << " " << c + 1;
		return 0;
	next:
		for (int j = 1; j < N; ++j)
		{
			if (arr[r][j] == arr[0][0]) goto next2;
		}
		cout << r + 1 << " " << 1;
		return 0;
	next2:;
	}
	cout << -1;

}