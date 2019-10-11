#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, seg[4 * 100'010], lazy[4*100'010];

void p(int n, int s, int e);
void u(int l, int r, int v, int n = 1, int s = 1, int e = 100'000);
int q(int i, int n = 1, int s = 1, int e = 100'000);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int l, r;
		cin >> l >> r;
		int al = q(l), ar = q(r);
		u(l, l, -al);
		u(r, r, -ar);
		if(r-l!=1)
			u(l + 1, r - 1, 1);
		cout << al+ar << "\n";
	}
}

void p(int n, int s, int e)
{
	if (!lazy[n]) return;
	seg[n] += (e - s + 1) * lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	for (int i : {n * 2, n * 2 + 1})
		lazy[i] += lazy[n];
	lazy[n] = 0;
}

void u(int l, int r, int v, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] += v; p(n, s, e); return; }
	int m = s + e >> 1;
	u(l, r, v, n * 2, s, m);
	u(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int q(int i, int n, int s, int e)
{
	p(n, s, e);
	if (s > i || e < i) return 0;
	if (s == e) return seg[n];
	int m = s + e >> 1;
	return q(i, n * 2, s, m) + q(i, n * 2 + 1, m + 1, e);
}