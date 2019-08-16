#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, Q;
lli tree[4 * 300'001];

void u(int i, int v, int n = 1, int s = 1, int e = N);
lli q(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i=1;i<=N;++i)
	{
		lli t;
		cin >> t;
		u(i, t);
	}
	while(Q--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			cout << abs(q(b, c)) << "\n";
		else
			u(b, c);
	}
}

void u(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	if (i & 1) tree[n] += v;
	else tree[n] -= v;
	if (s == e) return;
	int m = (s + e) >> 1;
	if (i <= m) u(i, v, 2 * n, s, m);
	else u(i, v, 2 * n + 1, m + 1, e);
}

lli q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[n];
	int m = (s + e) >> 1;
	return q(l, r, 2 * n, s, m) + q(l, r, 2 * n + 1, m + 1, e);
}