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
lli arr[200'010], S[200'010], T[200'010], ans = LLONG_MIN;
vector<Seg> tmp[2], & seg = tmp[0];

void u(lli a, lli b, int n = 1, lli s = -1e6, lli e = 1e6);
lli q(lli x, int n = 1, lli s = -1e6, lli e = 1e6);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 2; ++i) 
		for (int j = 0; j < 2; ++j) 
			tmp[i].emplace_back(Seg());
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		S[i] = S[i - 1] + arr[i];
		T[i] = T[i - 1] + i * arr[i];
	}
	for (int i = 1; i <= N; ++i)
	{
		u(i, -S[i - 1]);
		ans = max(ans, q(arr[i]) + T[N] - i * arr[i] + S[i - 1]);
	}
	seg = tmp[1];
	for (int i = N; i >= 1; --i)
	{
		u(i, -S[i]);
		ans = max(ans, q(arr[i]) + T[N] - i * arr[i] + S[i]);
	}
	cout << ans;

}

void u(lli a, lli b, int n, lli s, lli e)
{
	lli vl = a * s + b, vr = a * e + b;
	if (vl > seg[n].a* s + seg[n].b && vr > seg[n].a* e + seg[n].b)
	{
		seg[n].a = a; seg[n].b = b; return;
	}
	if (vl <= seg[n].a * s + seg[n].b && vr <= seg[n].a * e + seg[n].b) return;
	lli m = s + e >> 1;
	if (!seg[n].l)
	{
		seg[n].l = seg.size();
		seg.emplace_back(a, b);
	}
	else
		u(a, b, seg[n].l, s, m);
	if (!seg[n].r)
	{
		seg[n].r = seg.size();
		seg.emplace_back(a, b);
	}
	else
		u(a, b, seg[n].r, m + 1, e);
}

lli q(lli x, int n, lli s, lli e)
{
	lli ret = seg[n].a * x + seg[n].b;
	if (s == e) return ret;
	lli m = s + e >> 1;
	if (x <= m && seg[n].l) return max(ret, q(x, seg[n].l, s, m));
	if (x > m&& seg[n].r) return max(ret, q(x, seg[n].r, m + 1, e));
	return ret;
}