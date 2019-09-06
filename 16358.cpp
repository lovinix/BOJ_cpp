#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int INF = 123456789;
int M, N, d[501][501], arr[501][501];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0) arr[i][j] = INF;
		}
	}
	for (int i = 1; i <= M; ++i)
	{
		for (int j = i + 1; j <= M; ++j)
		{
			for (int k = 1; k <= N; ++k)
			{
				if (arr[k][i] > arr[k][j]) d[j][i]++;
				if (arr[k][i] < arr[k][j]) d[i][j]++;
			}
		}
	}
	for (int k = 1; k <= M; ++k)
	{
		for (int i = 1; i <= M; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if(d[i][k]>d[k][j])
					d[i][j] = max(d[i][j],min(d[i][k], d[k][j]));
			}
		}
	}
	for (int i = 1; i <= M; ++i)
	{
		int f = 1;
		for (int j = 1; j <= M; ++j)
		{
			if (d[i][j] < d[j][i]) { f = 0; break; }
		}
		if (f) cout << i << " ";
	}
}