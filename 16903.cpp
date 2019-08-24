#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Seg
{
	int l, r, v;
	Seg() : l(0), r(0), v(0) {}
};

int M;
lli MAX = (1 << 30) - 1;
vector<Seg> seg(2);

void u(int i, int v, int n = 1, lli s = 0, lli e = MAX);
int q(int x, int cnt = 29, int n = 1, lli s = 0, lli e = MAX);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	u(0, 1);
	cin >> M;
	while (M--)
	{
		int f, x;
		cin >> f >> x;
		if (f == 3)
			cout << (x^q(x)) << "\n";
		else
			u(x, f == 1 ? 1 : -1);
	}
}

void u(int i, int v, int n, lli s, lli e)
{
	if (s > i || e < i) return;
	seg[n].v += v;
	if (s == e) return;
	lli m = (s + e) >> 1;
	if(i<=m)
	{
		if(seg[n].l == 0)
		{
			seg[n].l = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, v, seg[n].l, s, m);
	}
	else
	{
		if (seg[n].r == 0)
		{
			seg[n].r = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, v, seg[n].r, m + 1, e);
	}
}

int q(int x, int cnt, int n, lli s, lli e)
{
	if (s == e)
		return s;
	lli m = (s + e) >> 1;
	if (seg[seg[n].r].v == 0 || (seg[seg[n].l].v && (1 << cnt & x)))
		return q(x, cnt - 1, seg[n].l, s, m);
	else
		return q(x, cnt - 1, seg[n].r, m + 1, e);
}