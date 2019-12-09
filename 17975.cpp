#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<lli, lli, int>;

struct Seg
{
	int l, r, lmx, rmx, mx, s;
	Seg() { l = r = lmx = rmx = mx = s = 0; }
	void set(int v) { lmx += v, rmx += v, mx += v, s += v; }
	void merge(Seg& s1, Seg& s2)
	{
		lmx = max(s1.lmx, s1.s + s2.lmx);
		rmx = max(s2.rmx, s2.s + s1.rmx);
		s = s1.s + s2.s;
		mx = max({ s1.rmx+s2.lmx, s1.mx, s2.mx });
	}
};

int N1, N2, C1, C2;
int ans = INT_MIN;
tu arr[2010];
vector<Seg> seg;

void u(int i, int v, int n = 1, lli s = 0, lli e = 2e9);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N1;
	for (int i = 0; i < N1; ++i)
	{
		lli x, y;
		cin >> x >> y;
		x += 1e9, y += 1e9;
		arr[i] = { x,y,1 };
	}
	cin >> N2;
	for (int i = 0; i < N2; ++i)
	{
		lli x, y;
		cin >> x >> y;
		x += 1e9, y += 1e9;
		arr[i + N1] = { x,y,-1 };
	}
	cin >> C1 >> C2;
	for (int i = 0; i < N1 + N2; ++i)
	{
		auto& [x, y, f] = arr[i];
		if (f == 1) f = C1;
		else f = -C2;
	}
	sort(arr, arr + N1 + N2);
	for (int i = 0; i < N1 + N2; ++i)
	{
		if (i != 0 && get<0>(arr[i - 1]) == get<0>(arr[i])) continue;
		seg.clear();
		for (int j = 0; j < 2; ++j) seg.emplace_back(Seg());
		for (int j = i; j < N1+N2; ++j)
		{
			auto& [x, y, v] = arr[j];
			u(y, v);
			if (j == N1 + N2 - 1 || get<0>(arr[j + 1]) != x)
				ans = max(ans, seg[1].mx);
		}
	}
	cout << ans;
}

void u(int i, int v, int n, lli s, lli e)
{
	if (s == e) { seg[n].set(v); return; }
	lli m = s + e >> 1;
	if (i <= m)
	{
		if (!seg[n].l)
		{
			seg[n].l = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, v, seg[n].l, s, m);
	}
	else
	{
		if (!seg[n].r)
		{
			seg[n].r = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, v, seg[n].r, m + 1, e);
	}
	seg[n].merge(seg[seg[n].l], seg[seg[n].r]);
}