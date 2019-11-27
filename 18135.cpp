#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;

int N, M, seg[4 * 2'000'010], lazy[4 * 2'000'010];
vector<pii> vt;

void p(int n, int s, int e);
void u(int l, int r, int v, int n = 1, int s = 0, int e = M - 1);
int q(int l, int r, int n = 1, int s = 0, int e = M - 1);

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vt.emplace_back(--a, --b);
		u(i, i, c);
	}
	int f, x, y, z;
	for (cin >> f; f != 0; cin >> f)
	{
		if (f == 1)
		{
			cin >> x >> y;
			x--, y--;
			int l = upper_bound(vt.begin(), vt.end(), pii(x, N)) - vt.begin() - 1;
			int r = upper_bound(vt.begin(), vt.end(), pii(y, N)) - vt.begin() - 1;
			if (x <= y)
				cout << q(l, r) << "\n";
			else
			{
				cout << q(l, M - 1) + q(0, r) << "\n";
			}
		}
		else
		{
			cin >> x >> y >> z;
			x--, y--;
			int l = upper_bound(vt.begin(), vt.end(), pii(x, N)) - vt.begin() - 1;
			int r = upper_bound(vt.begin(), vt.end(), pii(y, N)) - vt.begin() - 1;
			if (x <= y)
				u(l, r, z);
			else
			{
				u(l, M - 1, z);
				u(0, r, z);
			}
		}
	}
}

void p(int n, int s, int e)
{
	if (!lazy[n]) return;
	seg[n] += (e - s + 1) * lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[n * 2] += lazy[n];
	lazy[n * 2 + 1] += lazy[n];
	lazy[n] = 0;
}

void u(int l, int r, int v, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] += v; p(n, s, e); return; }
	int m = s + e >> 1;
	u(l, r, v, n * 2, s, m);
	u(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int q(int l, int r, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return q(l, r, n * 2, s, m) + q(l, r, n * 2 + 1, m + 1, e);
}