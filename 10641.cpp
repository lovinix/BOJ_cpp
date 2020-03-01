#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int>;

struct Seg
{
	int l, r;
	lli v, lz;
	Seg() { l = r = v = lz = 0; }
};

struct Query { int x, y, l, h, m, i; lli j; };

constexpr int sz = 100'010;
int N, M, Q, ans[sz], segsz = 2;
tu A[sz];
Query query[sz];
Seg seg[20'000'000];
vector<int> cc;

inline int getidx(int val)
{
	return lower_bound(cc.begin(), cc.end(), val) - cc.begin();
}

void pr(int n, int s, int e)
{
	if (!seg[n].lz) return;
	seg[n].v += (e - s + 1) * seg[n].lz;
	if (s == e) { seg[n].lz = 0; return; }
	if (!seg[n].l)
	{
		seg[segsz] = Seg();
		seg[n].l = segsz++;
	}
	if (!seg[n].r)
	{
		seg[segsz] = Seg();
		seg[n].r = segsz++;
	}
	seg[seg[n].l].lz += seg[n].lz;
	seg[seg[n].r].lz += seg[n].lz;
	seg[n].lz = 0;
}

void su(int l, int r, int n = 1, int s = 1, int e = N)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { seg[n].lz++; pr(n, s, e); return; }
	int m = s + e >> 1;
	if (!seg[n].l)
	{
		seg[segsz] = Seg();
		seg[n].l = segsz++;
	}
	su(l, r, seg[n].l, s, m);
	if (!seg[n].r)
	{
		seg[segsz] = Seg();
		seg[n].r = segsz++;
	}
	su(l, r, seg[n].r, m + 1, e);
	seg[n].v = seg[seg[n].l].v + seg[seg[n].r].v;
}

lli sq(int l, int r, int n = 1, int s = 1, int e = N)
{
	pr(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n].v;
	int m = s + e >> 1;
	return sq(l, r, seg[n].l, s, m) + sq(l, r, seg[n].r, m + 1, e);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> Q;
	for (int i = 0; i < M; ++i)
	{
		auto& [v, a, b] = A[i];
		cin >> a >> b >> v;
		cc.emplace_back(v);
	}
	sort(cc.begin(), cc.end());
	cc.erase(unique(cc.begin(), cc.end()), cc.end());
	sort(A, A + M);
	for (int i = 0; i < M; ++i)
	{
		auto& [v, a, b] = A[i];
		v = getidx(v);
	}
	for (int i = 0; i < Q; ++i)
	{
		auto& [x, y, l, r, m, idx, j] = query[i];
		cin >> x >> y >> j;
		l = 0, r = cc.size() - 1, m = l + r >> 1;
		idx = i;
	}
	int mxsz = 0;
	while (1)
	{
		int idx = 0, fl = 0;
		for (int i = 0; i < Q; ++i)
		{
			auto& [x, y, l, r, m, id, j] = query[i];
			while (idx < M && get<0>(A[idx]) <= m)
			{
				auto& [v, a, b] = A[idx++];
				su(a, b);
			}
			if (sq(x, y) >= j) { r = m - 1; ans[id] = m; }
			else { l = m + 1; }
			m = l + r >> 1;
			if (l <= r) fl = 1;
		}
		if (!fl) break;
		sort(query, query + Q, [](Query& q1, Query& q2) {return q1.m < q2.m; });
		segsz = 2;
		seg[1] = Seg();
	}
	for (int i = 0; i < Q; ++i)
	{
		cout << cc[ans[i]] << "\n";
	}
}