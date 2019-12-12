#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Seg
{
	int l, r;
	lli a, b;
	Seg() {l = r = a = 0; b = LLONG_MAX; }
	Seg(lli _a, lli _b) { l = r = 0; a = _a; b = _b; }
};

int N;
lli A[100'010], B[100'010], dp[100'010];
vector<Seg> seg(2);

void u(lli a, lli b, int n = 1, lli s = 0, lli e = 1e9);
lli q(lli x, int n = 1, lli s = 0, lli e = 1e9);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i)
		cin >> B[i];
	for (int i = 1; i < N; ++i)
	{
		u(B[i - 1], dp[i - 1]);
		dp[i] = q(A[i]);
	}
	cout << dp[N - 1];
}

void u(lli a, lli b, int n, lli s, lli e)
{
	lli vl = a * s + b, vr = a * e + b;
	if (vl < seg[n].a* s + seg[n].b && vr < seg[n].a* e + seg[n].b) { seg[n].a = a; seg[n].b = b; return; }
	if (vl >= seg[n].a * s + seg[n].b && vr >= seg[n].a * e + seg[n].b) return;
	lli m = s + e >> 1;
	if (!seg[n].l)
	{
		seg[n].l = seg.size();
		seg.emplace_back(Seg(seg[n].a, seg[n].b));
	}
	u(a, b, seg[n].l, s, m);
	if (!seg[n].r)
	{
		seg[n].r = seg.size();
		seg.emplace_back(Seg(seg[n].a, seg[n].b));
	}
	u(a, b, seg[n].r, m + 1, e);
}

lli q(lli x, int n, lli s, lli e)
{
	lli ret = seg[n].a * x + seg[n].b;
	if (s == e) return ret;
	lli m = s + e >> 1;
	if (x <= m && seg[n].l) return min(ret, q(x, seg[n].l, s, m));
	if (x > m&& seg[n].r) return min(ret, q(x, seg[n].r, m + 1, e));
	return ret;
}