#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Seg
{
	int l, r, v;
	Seg() : l(0), r(0), v(0) {}
};

int T, N, M, arr[100'010];
vector<Seg> seg;

void u(int i, int v, int n = 1, int s = 0, int e = 1'000'000'000);
int q(int k, int n = 1, int s = 0, int e = 1'000'000'000);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		seg.clear();
		for (int i = 0; i < 2; ++i) seg.emplace_back(Seg());
		for (int i = 1; i <= N; ++i)
		{
			arr[i] = 0;
			u(0, 1);
		}
		cin >> M;
		while (M--)
		{
			char f;
			int j, k;
			cin >> f;
			if (f == 'R')
			{
				cin >> j >> k;
				u(arr[j], -1);
				u(arr[j] + k, 1);
				arr[j] += k;
			}
			else
			{
				cin >> j;
				cout << q(arr[j]) + 1 << "\n";
			}
		}

	}
}

void u(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n].v += v;
	if (s == e) return;
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

}

int q(int k, int n, int s, int e)
{
	if (s == e) return 0;
	int m = s + e >> 1;
	if (k <= m) return q(k, seg[n].l, s, m) + seg[seg[n].r].v;
	else return q(k, seg[n].r, m + 1, e);
}