#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pll = pair<lli, lli>;

int N, Q;
lli lz[4 * 200'010];
pll seg[4 * 200'010], NIL = { LLONG_MAX, 0 };

void pr(int n, int s, int e)
{
	if (!lz[n]) return;
	seg[n].first += lz[n];
	seg[n].second += (e - s + 1) * lz[n];
	if (s == e) { lz[n] = 0; return; }
	lz[n * 2] += lz[n];
	lz[n * 2 + 1] += lz[n];
	lz[n] = 0;
}

pll& su(int l, int r, int v, int n = 1, int s = 1, int e = N)
{
	pr(n, s, e);
	if (s > r || e < l) return seg[n];
	if (l <= s && e <= r) { lz[n] += v; pr(n, s, e); return seg[n]; }
	int m = s + e >> 1;
	pll& lp = su(l, r, v, n * 2, s, m);
	pll& rp = su(l, r, v, n * 2 + 1, m + 1, e);
	seg[n].first = min(lp.first, rp.first);
	seg[n].second = lp.second + rp.second;
	return seg[n];
}

lli sq(char t, int l, int r, int n = 1, int s = 1, int e = N)
{
	pr(n, s, e);
	if (s > r || e < l) return t == 'M' ? NIL.first : NIL.second;
	if (l <= s && e <= r) return t == 'M' ? seg[n].first : seg[n].second;
	int m = s + e >> 1;
	if (t == 'M')
		return min(sq(t, l, r, n * 2, s, m), sq(t, l, r, n * 2 + 1, m + 1, e));
	else
		return sq(t, l, r, n * 2, s, m) + sq(t, l, r, n * 2 + 1, m + 1, e);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
	{
		int v; cin >> v;
		su(i, i, v);
	}
	while (Q--)
	{
		char t; int A, B, C;
		cin >> t;
		if (t == 'M' || t == 'S')
		{
			cin >> A >> B;
			cout << sq(t, A, B) << "\n";
		}
		else
		{
			cin >> A >> B >> C;
			su(A, B, C);
		}
	}
}