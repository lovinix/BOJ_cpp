#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int A[5][5], b;
pii pos[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
		{
			cin >> A[i][j];
			pos[A[i][j]] = { i,j };
		}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int v; cin >> v;
			int r = pos[v].first, c = pos[v].second;
			A[r][c] = 0;
			for (int n = 0; n < 5; ++n)
			{
				if (A[n][c]) goto n1;
			}
			b++;
		n1:
			for (int m = 0; m < 5; ++m)
			{
				if (A[r][m]) goto n2;
			}
			b++;
		n2:
			if (r != c) goto n3;
			for (int n = 0; n < 5; ++n)
			{
				if (A[n][n]) goto n3;
			}
			b++;
		n3:
			if (r + c != 4) goto n4;
			for (int n = 0; n < 5; ++n)
			{
				if (A[n][4 - n]) goto n4;
			}
			b++;
		n4:
			if (b >= 3) { cout << i * 5 + j + 1; return 0; }
		}
	}
}