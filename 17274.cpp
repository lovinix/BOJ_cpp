#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int>;

struct Seg
{
	int l, r, v;
	Seg(int val) : l(0), r(0), v(val) {}
};

const int MAX = 1'000'000'000;
int N, M, arr2[200'010];
lli ans;
tu arr1[200'010];
vector<Seg> seg1(2, Seg(-1)), seg2(2, Seg(0));

void u1(int i, int v, int n = 1, int s = 1, int e = MAX);
int q1(int l, int r, int n = 1, int s = 1, int e = MAX);
void u2(int i, int n = 1, int s = 1, int e = MAX);
int q2(int l, int r, int n = 1, int s = 1, int e = MAX);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int a, b; cin >> a >> b;
		arr1[i] = { a,b,-1 };
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> arr2[i];
		u1(arr2[i], i);
	}
	for (int i = 0; i < N; ++i)
	{
		auto [mn, mx, idx] = arr1[i];
		if (mn > mx) swap(mn, mx);
		get<2>(arr1[i]) = q1(mn, mx - 1);
	}
	sort(arr1, arr1 + N, [](tu& t1, tu& t2) {return get<2>(t1) > get<2>(t2); });
	int cur = M - 1;
	for (int i = 0; i < N; ++i)
	{
		auto [a, b, idx] = arr1[i];
		while (cur > idx) u2(arr2[cur--]);
		int cnt = q2(max(a, b), MAX);
		if (idx == -1) ans += cnt & 1 ? b : a;
		else ans += cnt & 1 ? min(a, b) : max(a, b);
	}
	cout << ans;
}

void u1(int i, int v, int n, int s, int e)
{
	if (e<i || s>i) return;
	if (s == e) { seg1[n] = v; return; }
	int m = s + e >> 1;
	if (i <= m)
	{
		if (!seg1[n].l)
		{
			seg1[n].l = seg1.size();
			seg1.emplace_back(Seg(-1));
		}
		u1(i, v, seg1[n].l, s, m);
	}
	else
	{
		if (!seg1[n].r)
		{
			seg1[n].r = seg1.size();
			seg1.emplace_back(Seg(-1));
		}
		u1(i, v, seg1[n].r, m + 1, e);
	}
	seg1[n].v = max(seg1[seg1[n].l].v, seg1[seg1[n].r].v);
}

int q1(int l, int r, int n, int s, int e)
{
	if (e<l || s>r) return -1;
	if (l <= s && e <= r) return seg1[n].v;
	int m = s + e >> 1;
	int ret = -1;
	if (seg1[n].l) ret = max(ret, q1(l, r, seg1[n].l, s, m));
	if (seg1[n].r) ret = max(ret, q1(l, r, seg1[n].r, m + 1, e));
	return ret;
}

void u2(int i, int n, int s, int e)
{
	if (s > i || e < i) return;
	if (s == e) { seg2[n].v++; return; }
	int m = s + e >> 1;
	if (i <= m)
	{
		if (!seg2[n].l)
		{
			seg2[n].l = seg2.size();
			seg2.emplace_back(Seg(0));
		}
		u2(i, seg2[n].l, s, m);
	}
	else
	{
		if (!seg2[n].r)
		{
			seg2[n].r = seg2.size();
			seg2.emplace_back(Seg(0));
		}
		u2(i, seg2[n].r, m + 1, e);
	}
	seg2[n].v = seg2[seg2[n].l].v + seg2[seg2[n].r].v;
}

int q2(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg2[n].v;
	int m = s + e >> 1;
	int ret = 0;
	if (seg2[n].l) ret += q2(l, r, seg2[n].l, s, m);
	if (seg2[n].r) ret += q2(l, r, seg2[n].r, m + 1, e);
	return ret;
}