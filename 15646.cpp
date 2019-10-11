#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M, Q;
lli fw[5010][5010];

void u(int r, int c, int v);
lli q(int r, int c);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> Q;
	while (Q--)
	{
		int f, x1, y1, x2, y2, d;
		cin >> f;
		if (f == 1)
		{
			cin >> x1 >> y1 >> x2 >> y2 >> d;
			u(x1, y1, d);
			u(x2 + 1, y1, -d);
			u(x1, y2 + 1, -d);
			u(x2 + 1, y2 + 1, d);
		}
		else
		{
			cin >> x1 >> y1;
			cout << q(x1, y1) << "\n";
		}
	}
}

void u(int r, int c, int v)
{
	int n = r;
	while (n <= N)
	{
		int m = c;
		while (m <= M)
		{
			fw[n][m] += v;
			m += m & -m;
		}
		n += n & -n;
	}
}

lli q(int r, int c)
{
	lli ret = 0;
	int n = r;
	while (n)
	{
		int m = c;
		while (m)
		{
			ret += fw[n][m];
			m -= m & -m;
		}
		n -= n & -n;
	}
	return ret;
}