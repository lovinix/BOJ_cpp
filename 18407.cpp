#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;

struct Seg
{
	int l, r, v, lz;
	Seg() { l = r = v = lz = 0; }
};

int N;
vector<Seg> seg(2);

void pr(int n, uint s, uint e)
{
	if (!seg[n].lz) return;
	seg[n].v = max(seg[n].v, seg[n].lz);
	if (s == e) { seg[n].lz = 0; return; }
	if (!seg[n].l)
	{
		seg[n].l = seg.size();
		seg.emplace_back(Seg());
	}
	seg[seg[n].l].lz = max(seg[seg[n].l].lz, seg[n].lz);
	if (!seg[n].r)
	{
		seg[n].r = seg.size();
		seg.emplace_back(Seg());
	}
	seg[seg[n].r].lz = max(seg[seg[n].r].lz, seg[n].lz);
	seg[n].lz = 0;
}

void su(int l, int r, int v, int n = 1, uint s = 1, uint e = 2e9 + 1)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { seg[n].lz = max(seg[n].lz, v); pr(n, s, e); return; }
	uint m = s + e >> 1;
	if (!seg[n].l)
	{
		seg[n].l = seg.size();
		seg.emplace_back(Seg());
	}
	su(l, r, v, seg[n].l, s, m);
	if (!seg[n].r)
	{
		seg[n].r = seg.size();
		seg.emplace_back(Seg());
	}
	su(l, r, v, seg[n].r, m + 1, e);
	seg[n].v = max(seg[seg[n].l].v, seg[seg[n].r].v);
}

int sq(int l, int r, int n = 1, uint s = 1, uint e = 2e9 + 1)
{
	pr(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n].v;
	uint m = s + e >> 1;
	return max(sq(l, r, seg[n].l, s, m), sq(l, r, seg[n].r, m + 1, e));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--)
	{
		int w, d;
		cin >> w >> d;
		su(d, d + w - 1, sq(d, d + w - 1) + 1);
	}
	cout << sq(1, 2e9 + 1);
}