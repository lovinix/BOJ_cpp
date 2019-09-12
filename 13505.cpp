#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Seg
{
	int l, r, v;
	Seg() :l(0), r(0), v(0) {}
};

const int MAX = (1 << 30) - 1;
int N, arr[100'010];
vector<Seg> seg(2);

void u(int i, int n = 1, int s = 0, int e = MAX);
int q(int v, int cnt = 29, int n = 1, int s = 0, int e = MAX);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		u(arr[i]);
	}
	int mx = 0;
	for (int i = 0; i < N; ++i)
	{
		mx = max(mx, (arr[i] ^ q(arr[i])));
	}
	cout << mx;
}

void u(int i, int n, int s, int e)
{
	if (e < i || s > i) return;
	seg[n].v++;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m)
	{
		if (!seg[n].l)
		{
			seg[n].l = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, seg[n].l, s, m);
	}
	else
	{
		if (!seg[n].r)
		{
			seg[n].r = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, seg[n].r, m + 1, e);
	}
}

int q(int v, int cnt, int n, int s, int e)
{
	if (s == e) return s;
	int m = s + e >> 1;
	if (!seg[n].r || (seg[n].l && (v & (1 << cnt))))
		return q(v, cnt - 1, seg[n].l, s, m);
	else
		return q(v, cnt - 1, seg[n].r, m + 1, e);
}