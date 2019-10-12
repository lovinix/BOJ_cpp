#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, Q1, Q2, arr[1'000'010];
lli seg[4 * 1'000'010], lazy[4 * 1'000'010];

lli init(int n = 1, int s = 1, int e = N);
void p(int n, int s, int e);
void u(int l, int r, int v, int n = 1, int s = 1, int e = N);
lli q(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q1 >> Q2;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	init();
	for (int i = 0; i < Q1 + Q2; ++i)
	{
		int f, n, m, s, e, l;
		cin >> f;
		if (f == 1)
		{
			cin >> n >> m;
			cout << q(n, m) << "\n";
		}
		else
		{
			cin >> s >> e >> l;
			u(s, e, l);
		}
	}
}

lli init(int n, int s, int e)
{
	if (s == e) return seg[n] = arr[s];
	int m = s + e >> 1;
	return seg[n] = init(n * 2, s, m) + init(n * 2 + 1, m + 1, e);
}

void p(int n, int s, int e)
{
	if (!lazy[n]) return;
	seg[n] += (e - s + 1) * lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[n * 2] += lazy[n];
	lazy[n * 2 + 1] += lazy[n];
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

lli q(int l, int r, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return q(l, r, n * 2, s, m) + q(l, r, n * 2 + 1, m + 1, e);
}