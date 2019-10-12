#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define MAX 500'010
using namespace std;

int N, M, arr[MAX], seg[4 * MAX], lazy[4 * MAX];

void p(int n, int s, int e);
int init(int n = 1, int s = 1, int e = N);
void u(int l, int r, int v, int n = 1, int s = 1, int e = N);
int q(int i, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	init();
	cin >> M;
	while (M--)
	{
		int f, a, b, c;
		cin >> f;
		if (f == 1)
		{
			cin >> a >> b >> c;
			++a, ++b;
			u(a, b, c);
		}
		else
		{
			cin >> a;
			++a;
			cout << q(a) << "\n";
		}
	}
}

void p(int n, int s, int e)
{
	if (!lazy[n]) return;
	if ((e - s + 1) & 1) seg[n] ^= lazy[n];
	if (e == s) { lazy[n] = 0; return; }
	lazy[n * 2] ^= lazy[n];
	lazy[n * 2 + 1] ^= lazy[n];
	lazy[n] = 0;
}

int init(int n, int s, int e)
{
	if (s == e) { return seg[n] = arr[s]; }
	int m = s + e >> 1;
	return seg[n] = init(n * 2, s, m) ^ init(n * 2 + 1, m + 1, e);
}

void u(int l, int r, int v, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] ^= v; p(n, s, e); return; }
	int m = s + e >> 1;
	u(l, r, v, n * 2, s, m);
	u(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] ^ seg[n * 2 + 1];
}

int q(int i, int n, int s, int e)
{
	p(n, s, e);
	if (i<s || i>e) return 0;
	if (s == e) return seg[n];
	int m = s + e >> 1;
	return q(i, n * 2, s, m) ^ q(i, n * 2 + 1, m + 1, e);
}