#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, Q, fw[1010][1010];

void u(int n, int m, int v)
{
	while (n <= N)
	{
		int t = m;
		while (t <= M)
		{
			fw[n][t] += v;
			t += t & -t;
		}
		n += n & -n;
	}
}

int q(int n, int m)
{
	int ret = 0;
	while (n)
	{
		int t = m;
		while (t)
		{
			ret += fw[n][t];
			t -= t & -t;
		}
		n -= n & -n;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int v; cin >> v;
			u(i, j, v);
		}
	}
	while (Q--)
	{
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;
		cout << (q(X2, Y2) - q(X2, Y1 - 1) - q(X1 - 1, Y2) + q(X1 - 1, Y1 - 1)) / ((X2 - X1 + 1) * (Y2 - Y1 + 1)) << "\n";
	}
}