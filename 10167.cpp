#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int>;

struct Seg
{
	int l, r;
	lli lmx, rmx, mx, s;
	Seg() { l = r = lmx = rmx = mx = s = 0; }
	void merge(Seg& s1, Seg& s2)
	{
		lmx = max(s1.lmx, s1.s + s2.lmx);
		rmx = max(s2.rmx, s1.rmx + s2.s);
		mx = max({ lmx, rmx, s1.mx, s2.mx, s1.rmx + s2.lmx });
		s = s1.s + s2.s;
	}
	void set(int v) { lmx += v, rmx += v, mx += v, s += v; }
};

int N;
lli ans = LLONG_MIN;
tu arr[3010];
vector<Seg> seg;

void u(int i, int v, int n = 1, int s = 0, int e = 1e9);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;
		arr[i] = { x,y,w };
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i)
	{
		if (i != 0 && get<0>(arr[i - 1]) == get<0>(arr[i])) continue;
		seg.clear();
		for (int j = 0; j < 2; ++j) seg.emplace_back(Seg());
		for (int j = i; j < N; ++j)
		{
			auto& [x, y, w] = arr[j];
			u(y, w);
			if (j == N - 1 || get<0>(arr[j + 1]) != x)
				ans = max(ans, seg[1].mx);
		}
	}
	cout << ans;
}

void u(int i, int v, int n, int s, int e)
{
	if (s == e) { seg[n].set(v); return; }
	int m = s + e >> 1;
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

