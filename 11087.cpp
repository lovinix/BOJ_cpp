#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long;

int N, R, S, X, Y, W;
lli dp[30][30];

lli pow(lli a, lli b);
lli recv(lli r, lli c);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> R >> S >> X >> Y >> W;
		lli t1 = 0;
		for (int i = X; i <= Y; ++i)
		{
			t1 += recv(Y, i) * pow(S - R + 1, i) * pow(R - 1, Y - i);
		}
		lli t2 = pow(S, Y);
		if (t1 * W > t2)  cout << "yes\n"; 
		else cout << "no\n";
	}
}

lli pow(lli a, lli b)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}

lli recv(lli r, lli c)
{
	if (dp[r][c]) return dp[r][c];
	if (r == c || c == 0) return dp[r][c] = 1;
	return dp[r][c] = recv(r - 1, c - 1) + recv(r - 1, c);
}