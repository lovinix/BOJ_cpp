#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MAX = 100'010, MOD = 1e9+7;
int N, M;
lli seg[4 * MAX], lazy[2][4 * MAX];

void pr(int n, int s, int e);
void su(int l, int r, int t, int v, int n = 1, int s = 1, int e = N);
lli sq(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int t; cin >> t;
		su(i, i, 0, t);
	}
	cin >> M;
	while (M--)
	{
		int f, x, y, v;
		cin >> f;
		switch (f)
		{
		case 1:
		case 2:
			cin >> x >> y >> v;
			su(x, y, f - 1, v);
			break;
		case 3:
			cin >> x >> y >> v;
			su(x, y, 1, 0);
			su(x, y, 0, v);
			break;
		case 4:
			cin >> x >> y;
			cout << sq(x, y) << "\n";
		}
	}
}

void pr(int n, int s, int e)
{
	if (lazy[0][n] == 0 && lazy[1][n] == 1) return;
	seg[n] = (seg[n] * lazy[1][n]) % MOD;
	seg[n] = (seg[n] + (e - s + 1) * lazy[0][n]) % MOD;
	if (s == e) { lazy[0][n] = 0; lazy[1][n] = 1; return; }
	for (int i = 0; i < 2; ++i)
	{
		lazy[0][n * 2 + i] = (lazy[0][n * 2 + i] * lazy[1][n]) % MOD;
		lazy[0][n * 2 + i] = (lazy[0][n * 2 + i] + lazy[0][n]) % MOD;
		lazy[1][n * 2 + i] = (lazy[1][n * 2 + i] * lazy[1][n]) % MOD;
	}
	lazy[0][n] = 0;
	lazy[1][n] = 1;
}

void su(int l, int r, int t, int v, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if(l<=s && e<=r) 
	{
		if (t)
		{
			lazy[1][n] = (lazy[1][n] * v) % MOD;
			lazy[0][n] = (lazy[0][n] * v) % MOD;
		}
		else
			lazy[0][n] = (lazy[0][n] + v) % MOD;
		pr(n, s, e);
		return;
	}
	int m = s + e >> 1;
	su(l, r, t, v, n * 2, s, m);
	su(l, r, t, v, n * 2 + 1, m + 1, e);
	seg[n] = (seg[n * 2] + seg[n * 2 + 1]) % MOD;
}

lli sq(int l, int r, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return (sq(l, r, n * 2, s, m) + sq(l, r, n * 2 + 1, m + 1, e)) % MOD;
}