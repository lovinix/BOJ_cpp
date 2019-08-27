#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, Q;
lli fw[1'000'001];

void u(int i, int v);
lli q(int i);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	while (Q--)
	{
		int f, p, l, x, r;
		cin >> f;
		if (f == 1)
		{
			cin >> p >> x;
			u(p, x);
		}
		else
		{
			cin >> l >> r;
			cout << q(r) - q(l - 1) << "\n";
		}
	}
}

void u(int i, int v)
{
	while (i <= N)
	{
		fw[i] += v;
		i += i & -i;
	}
}

lli q(int i)
{
	lli ret = 0;
	while (i)
	{
		ret += fw[i];
		i -= i & -i;
	}
	return ret;
}