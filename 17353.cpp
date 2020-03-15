#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, Q;
lli A[100'010], seg[4 * 100'010], lazy[4 * 100'010];

void pr(int n, int s, int e)
{
	if (!lazy[n]) return;
	seg[n] += (e - s + 1) * lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[n * 2] += lazy[n];
	lazy[n * 2 + 1] += lazy[n];
	lazy[n] = 0;
}

void su(int l, int r, int v, int n = 1, int s = 1, int e = N + 1)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] += v; pr(n, s, e); return; }
	int m = s + e >> 1;
	su(l, r, v, n * 2, s, m);
	su(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

lli sq(int l, int r, int n = 1, int s = 1, int e = N + 1)
{
	pr(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return sq(l, r, n * 2, s, m) + sq(l, r, n * 2 + 1, m + 1, e);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	cin >> Q;
	while (Q--)
	{
		int f, l, r, x;
		cin >> f;
		if (f == 1)
		{
			cin >> l >> r;
			su(l, r, 1);
			su(r + 1, r + 1, -(r - l + 1));
		}
		else
		{
			cin >> x;
			cout << A[x] + sq(1,x) << "\n";
		}
	}
}