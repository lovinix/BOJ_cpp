#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int A[1010][1010], C, R, dn[] = { 1,0,-1,0 }, dm[] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> C >> R;
	int cur = 1, d = 0, n = 1, m = 1, t = 1, b = R, l = 1, r = C;
	while (cur <= C * R)
	{
		A[n][m] = cur++;
		n += dn[d], m += dm[d];
		if (n<t || n>b || m<l || m>r) 
		{
			n -= dn[d]; m -= dm[d];
			if (n == t && m == l) { d = (d + 1) % 4; ++t; }
			else if (n == b && m == l) { d = (d + 1) % 4; ++l; }
			else if (n == b && m == r) { d = (d + 1) % 4; --b; }
			else if (n == t && m == r) { d = (d + 1) % 4; --r; }
			n += dn[d]; m += dm[d];
		}
	}
	int K;
	cin >> K;
	if (K > C* R) { cout << "0"; }
	else
	{
		for (int i = 1; i <= R; ++i)
			for (int j = 1; j <= C; ++j)
				if (A[i][j] == K) cout << j << " " << i;
	}
}