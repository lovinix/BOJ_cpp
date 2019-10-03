#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
string arr[501];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	if (M & 1)
	{
		for (int i = 0; i < N / 2; ++i)
			if (arr[i][M / 2] == '8' && arr[N - i - 1][M / 2] == '8')
				continue;
			else if (arr[i][M / 2] == '7' && arr[N - i - 1][M / 2] == '7')
				++ans;
			else if (arr[i][M / 2] == '6')
			{
				if (arr[N - i - 1][M / 2] == '9') continue;
				if (arr[N - i - 1][M / 2] == '6') ++ans;
				else { cout << -1; return 0; }
			}
			else if (arr[i][M / 2] == '9')
			{
				if (arr[N - i - 1][M / 2] == '6') continue;
				if (arr[N - i - 1][M / 2] == '9') ++ans;
				else { cout << -1; return 0; }
			}
			else
			{
				cout << -1; return 0;
			}
	}
	if (N & 1)
	{
		for (int j = 0; j < M / 2; ++j)
			if (arr[N / 2][j] == '8' && arr[N / 2][M - j - 1] == '8')
				continue;
			else if (arr[N / 2][j] == '7' && arr[N / 2][M - j - 1] == '7')
				++ans;
			else if (arr[N / 2][j] == '6')
			{
				if (arr[N / 2][M - j - 1] == '9') continue;
				if (arr[N / 2][M - j - 1] == '6') ++ans;
				else { cout << -1; return 0; }
			}
			else if (arr[N / 2][j] == '9')
			{
				if (arr[N / 2][M - j - 1] == '6') continue;
				if (arr[N / 2][M - j - 1] == '9') ++ans;
				else { cout << -1; return 0; }
			}
			else
			{
				cout << -1; return 0;
			}
	}
	if((N&1) && (M&1))
		if (arr[N / 2][M / 2] != '8') { cout << -1; return 0; }
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M / 2; ++j)
		{
			if ((N&1) && i == N / 2) continue;
			switch (arr[i][j])
			{
			case '6':
				if (arr[N - i - 1][M - j - 1] == '6') ++ans;
				else if (arr[N - i - 1][M - j - 1] == '9') continue;
				else { cout << -1; return 0; }
				break;
			case '7':
				if (arr[N - i - 1][M - j - 1] == '7') ++ans;
				else { cout << -1; return 0; }
				break;
			case '8':
				if (arr[N - i - 1][M - j - 1] != '8')
				{
					cout << -1; return 0;
				}
				break;
			case '9':
				if (arr[N - i - 1][M - j - 1] == '6') continue;
				else if (arr[N - i - 1][M - j - 1] == '9') ++ans;
				else { cout << -1; return 0; }
				break;
			}
		}
	}
	cout << ans;
}