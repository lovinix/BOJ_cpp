#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K, arr[1010][1010], dn[] = { -1,0,1,0 }, dm[] = { 0,1,0,-1 };


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	int n = 500, m = 500, i = 0, cnt = 1, cur = 1;
	arr[n][m] = cur++;
	while (cur<=N*N)
	{
		for (int t = 0; t < cnt; ++t)
		{
			n += dn[i]; m += dm[i];
			arr[n][m] = cur++;
		}
		i = (i + 1) % 4;
		for (int t = 0; t < cnt; ++t)
		{
			n += dn[i]; m += dm[i];
			arr[n][m] = cur++;
		}
		i = (i + 1) % 4;
		cnt++;
	}
	int ansi, ansj;
	for (int i = 500 - N / 2; i <= 500 + N / 2; ++i)
	{
		for (int j = 500 - N / 2; j <= 500 + N / 2; ++j)
		{
			cout << arr[i][j] << " ";
			if (arr[i][j] == K) { ansi = i; ansj = j; }
		}
		cout << '\n';
	}
	cout << ansi - (500 - N / 2) + 1 << " " << ansj - (500 - N / 2) + 1;
}