#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[500'001], tree[4 * 500'001], lazy[4 * 500'001];

void i(int n = 1, int s = 0, int e = N - 1);
void u(int l, int r, int v, int n = 1, int s = 0, int e = N - 1);
int q(int l, int r, int n = 1, int s = 0, int e = N - 1);
void p(int n, int s, int e);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	i();
	cin >> M;
	while (M--)
	{
		int f, a, b, c;
		cin >> f;
		if (f == 1)
		{
			cin >> a >> b >> c;
			if (a > b) swap(a, b);
			u(a, b, c);
		}
		else
		{
			cin >> a >> b;
			if (a > b) swap(a, b);
			cout << q(a, b) << "\n";
		}
	}

}

void i(int n, int s, int e)
{
	if (s == e) { tree[n] = arr[s]; return; }
	int m = s + e >> 1;
	i(n * 2, s, m);
	i(n * 2 + 1, m + 1, e);
	tree[n] = tree[n * 2] ^ tree[n * 2 + 1];
}

void u(int l, int r, int v, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] ^= v; p(n, s, e); return; }
	int m = s + e >> 1;
	u(l, r, v, n * 2, s, m);
	u(l, r, v, n * 2 + 1, m + 1, e);
	tree[n] = tree[n * 2] ^ tree[n * 2 + 1];
}

int q(int l, int r, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[n];
	int m = s + e >> 1;
	return q(l, r, n * 2, s, m) ^ q(l, r, n * 2 + 1, m + 1, e);
}

void p(int n, int s, int e)
{
	if (!lazy[n]) return;
	if ((e - s + 1) & 1) tree[n] ^= lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[n * 2] ^= lazy[n];
	lazy[n * 2 + 1] ^= lazy[n];
	lazy[n] = 0;
}