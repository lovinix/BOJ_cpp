#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, A[100'010], seg[4 * 100'010];

int init(int n = 1, int s = 1, int e = N)
{
	if (s == e) { return seg[n] = A[s]; }
	int m = s + e >> 1;
	return seg[n] = init(n * 2, s, m) + init(n * 2 + 1, m + 1, e);
}

void upd(int i, int v, int n = 1, int s = 1, int e = N)
{
	if (s > i || e < i) return;
	if (s == e) { seg[n] = v; return; }
	int m = s + e >> 1;
	upd(i, v, n * 2, s, m);
	upd(i, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int qry(int l, int r, int n = 1, int s = 1, int e = N)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return qry(l, r, n * 2, s, m) + qry(l, r, n * 2 + 1, m + 1, e);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
		A[i] = A[i] & 1;
	}
	init();
	cin >> M;
	while (M--)
	{
		int f, l, r;
		cin >> f >> l >> r;
		if (f == 1) upd(l, r & 1);
		else
		{
			cout << (f == 2 ? (r - l + 1) - qry(l, r) : qry(l, r)) << "\n";
		}
	}
}