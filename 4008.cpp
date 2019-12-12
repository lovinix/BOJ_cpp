#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Seg
{
	int l, r;
	lli a, b;
	Seg() { l = r = a = 0; b = LLONG_MIN; }
	Seg(lli _a, lli _b) { l = r = 0; a = _a; b = _b; }
};

int N;
lli a, b, c, dp, psum;
vector<Seg> seg(2);

void u(lli a, lli b, int n = 1, lli s = 0, lli e = 1e8);
lli q(lli x, int n = 1, lli s = 0, lli e = 1e8);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	seg.reserve(2'300'000);
	cin >> N >> a >> b >> c;
	for (int i = 1; i <= N; ++i)
	{
		lli t;
		cin >> t;
		u(-2 * a * psum, a * psum * psum - b * psum + dp);
		psum += t;
		dp = q(psum) + a * psum * psum + b * psum + c;
	}
	cout << dp;

}

void u(lli a, lli b, int n, lli s, lli e)
{
	lli vl = a * s + b, vr = a * e + b;
	if (vl <= seg[n].a * s + seg[n].b && vr <= seg[n].a * e + seg[n].b) return;
	if (vl > seg[n].a* s + seg[n].b && vr > seg[n].a* e + seg[n].b)
	{
		seg[n].a = a; seg[n].b = b; return;
	}
	lli m = s + e >> 1;
	if (!seg[n].l)
	{
		seg[n].l = seg.size();
		seg.emplace_back(Seg(a, b));
	}
	else
		u(a, b, seg[n].l, s, m);
	if (!seg[n].r)
	{
		seg[n].r = seg.size();
		seg.emplace_back(Seg(a, b));
	}
	else
		u(a, b, seg[n].r, m + 1, e);
}

lli q(lli x, int n, lli s, lli e)
{
	lli ret = x * seg[n].a + seg[n].b;
	if (s == e) return ret;
	lli m = s + e >> 1;
	if (x <= m && seg[n].l) return max(ret, q(x, seg[n].l, s, m));
	if (x > m&& seg[n].r) return max(ret, q(x, seg[n].r, m + 1, e));
	return ret;
}