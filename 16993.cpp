#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Seg
{
	int l, r, s, mx;
	Seg operator+(Seg& n)
	{
		auto cur = Seg();
		cur.l = max(l, s + n.l);
		cur.r = max(n.r, r + n.s);
		cur.s = s + n.s;
		cur.mx = max({ cur.l,cur.r, mx, n.mx, r+n.l });
		return cur;
	}
};

int N, M, arr[100'010];
Seg seg[4 * 100'010], ret;

void init(int n = 1, int s = 1, int e = N);
void q(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}
	init();
	cin >> M;
	while (M--)
	{
		int l, r;
		cin >> l >> r;
		ret = { -1'000'000'000,-1'000'000'000, 0,-1'000'000'000 };
		q(l, r);
		cout << max({ ret.l,ret.r,ret.mx }) << "\n";
	}
}

void init(int n, int s, int e)
{
	if (s == e) { seg[n] = { arr[s],arr[s],arr[s],arr[s] }; return; }
	int m = s + e >> 1;
	init(n * 2, s, m);
	init(n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return;
	if (l <= s && e <= r) { ret = ret + seg[n]; return; }
	int m = s + e >> 1;
	q(l, r, n * 2, s, m);
	q(l, r, n * 2 + 1, m + 1, e);
}