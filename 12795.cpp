#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Seg
{
	int l, r;
	lli a, b, vl, vr;
	Seg() : l(0), r(0), a(0), b(LLONG_MIN), vl(LLONG_MIN), vr(LLONG_MIN) {}
	Seg(lli _a, lli _b, lli s, lli e) : l(0), r(0), a(_a), b(_b), vl(_a*s+_b), vr(_a*e+_b) {}
};

int Q;
vector<Seg> seg(2);

void u(lli a, lli b, int n = 1, lli s = -1e12, lli e = 1e12);
lli q(lli x, int n = 1, lli s = -1e12, lli e = 1e12);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		int f;
		cin >> f;
		if (f == 1)
		{
			lli a, b;
			cin >> a >> b;
			u(a, b);
		}
		else
		{
			lli x;
			cin >> x;
			cout << q(x) << "\n";
		}
	}
}

void u(lli a, lli b, int n, lli s, lli e)
{
	lli vl = a * s + b, vr = a * e + b;
	if (vl > seg[n].vl && vr > seg[n].vr)
	{
		seg[n].a = a; seg[n].b = b; seg[n].vl = vl; seg[n].vr = vr; return;
	}
	if (vl <= seg[n].vl && vr <= seg[n].vr) return;
	lli m = s + e >> 1;
	if (!seg[n].l)
	{
		seg[n].l = seg.size();
		seg.emplace_back(Seg(seg[n].a, seg[n].b, s, m));
	}
	u(a, b, seg[n].l, s, m);
	if (!seg[n].r)
	{
		seg[n].r = seg.size();
		seg.emplace_back(Seg(seg[n].a, seg[n].b, m + 1, e));
	}
	u(a, b, seg[n].r, m + 1, e);
}

lli q(lli x, int n, lli s, lli e)
{
	lli ret = seg[n].a * x + seg[n].b;
	if (s == e) return ret;
	lli m = s + e >> 1;
	if (x <= m && seg[n].l) return max(ret, q(x, seg[n].l, s, m));
	else if (x > m&& seg[n].r) return max(ret, q(x, seg[n].r, m + 1, e));
	return ret;
}