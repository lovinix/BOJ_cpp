#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Seg
{
	int mx, mx2, cnt; lli sum;
};

int N, M, arr[1'000'010];
Seg seg[4'000'010];

Seg calc(Seg& a, Seg& b);
Seg& init(int n = 1, int s = 1, int e = N);
void prop(int n, int s, int e);
void u(int l, int r, int v, int n = 1, int s = 1, int e = N);
int q2(int l, int r, int n = 1, int s = 1, int e = N);
lli q3(int l, int r, int n = 1, int s = 1, int e = N);

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
		int f, l, r, x;
		cin >> f;
		switch (f)
		{
		case 1:
			cin >> l >> r >> x;
			u(l, r, x);
			break;
		case 2:
		case 3:
			cin >> l >> r;
			cout << (f == 2 ? q2(l, r) : q3(l, r)) << "\n";
		}
	}
}

Seg calc(Seg& a, Seg& b)
{
	if (a.mx == b.mx) return { a.mx, max(a.mx2,b.mx2), a.cnt + b.cnt, a.sum + b.sum };
	Seg& mx = a.mx > b.mx ? a : b;
	Seg& mn = a.mx > b.mx ? b : a;
	return { mx.mx,max(mx.mx2,mn.mx),mx.cnt,mx.sum + mn.sum };
}

Seg& init(int n, int s, int e)
{
	if (s == e) return seg[n] = { arr[s],INT_MIN,1,arr[s] };
	int m = s + e >> 1;
	return seg[n] = calc(init(n * 2, s, m), init(n * 2 + 1, m + 1, e));
}

void prop(int n, int s, int e)
{
	if (s == e) return;
	for (int i = n * 2; i <= n * 2 + 1; ++i)
	{
		if (seg[n].mx < seg[i].mx)
		{
			seg[i].sum -= 1LL * seg[i].cnt * (seg[i].mx - seg[n].mx);
			seg[i].mx = seg[n].mx;
		}
	}
}

void u(int l, int r, int v, int n, int s, int e)
{
	prop(n, s, e);
	if (s > r || e < l || seg[n].mx <= v) return;
	if (l <= s && e <= r && seg[n].mx2 < v) 
	{
		seg[n].sum -= 1LL * seg[n].cnt * (seg[n].mx - v); seg[n].mx = v; prop(n, s, e); return;
	}
	int m = s + e >> 1;
	u(l, r, v, n * 2, s, m);
	u(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = calc(seg[n * 2], seg[n * 2 + 1]);
}

int q2(int l, int r, int n, int s, int e)
{
	prop(n, s, e);
	if (s > r || e < l) return -1;
	if (l <= s && e <= r) return seg[n].mx;
	int m = s + e >> 1;
	return max(q2(l, r, n * 2, s, m), q2(l, r, n * 2 + 1, m + 1, e));
}

lli q3(int l, int r, int n, int s, int e)
{
	prop(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n].sum;
	int m = s + e >> 1;
	return q3(l, r, n * 2, s, m) + q3(l, r, n * 2 + 1, m + 1, e);
}

