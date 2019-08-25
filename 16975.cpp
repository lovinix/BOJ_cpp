#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M;
lli tree[4 * 100'001], lazy[4 * 100'001];

void u(int l, int r, int v, int n = 1, int s = 1, int e = N);
int q(int i, int n = 1, int s = 1, int e = N);
void p(int n, int s, int e);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int t;
		cin >> t;
		u(i, i, t);
	}
	cin >> M;
	while (M--)
	{
		int f, i, j, k, x;
		cin >> f;
		if (f == 1)
		{
			cin >> i >> j >> k;
			u(i, j, k);
		}
		else
		{
			cin >> x;
			cout << q(x) << "\n";
		}
	}
}

void u(int l, int r, int v, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] += v; return; }
	int m = s + e >> 1;
	u(l, r, v, n * 2, s, m);
	u(l, r, v, n * 2 + 1, m + 1, e);
}

int q(int i, int n, int s, int e)
{
	p(n, s, e);
	if (s == e) return tree[n];
	int m = s + e >> 1;
	if (i <= m) return q(i, n * 2, s, m);
	else return q(i, n * 2 + 1, m + 1, e);
}

void p(int n, int s, int e)
{
	tree[n] += (e - s + 1) * lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[2 * n] += lazy[n];
	lazy[2 * n + 1] += lazy[n];
	lazy[n] = 0;
}