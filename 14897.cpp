#include <bits/stdc++.h>
#define INF 1'000'001
using namespace std;
using pii = pair<int, int>;

struct Pst
{
	int l, r, v;
	Pst() :l(0), r(0), v(0) {}
};

int N, M, arr[1'000'001], cnt[1'000'001];
vector<Pst> pst(1'000'001);
vector<pii> v(1);
vector<int> z;

void u(int i1, int i2, int v, int s = 0, int e = INF);
int q(int i1, int i2, int l, int r, int s = 0, int e = INF);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		z.emplace_back(arr[i]);
	}
	sort(z.begin(), z.end());
	z.erase(unique(z.begin(), z.end()), z.end());
	for (int i = 1; i <= N; ++i)
	{
		int val = lower_bound(z.begin(), z.end(), arr[i - 1]) - z.begin();
		if (cnt[val])
			v[cnt[val]].second = i;
		v.emplace_back(i, -1);
		cnt[val] = i;
	}
	for (int i = v.size() - 1; v[i].second == -1; --i) v[i].second = INF;
	for (int i = 1, j = 1; i < INF; ++i)
	{
		pst[i] = pst[i - 1];
		while (j < v.size() && v[j].first == i) u(i - 1, i, v[j++].second);
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int l, r;
		cin >> l >> r;
		cout << r - l - q(l - 1, r, l - 1, r) + 1 << "\n";
	}
}

void u(int i1, int i2, int v, int s, int e)
{
	if (e<v || s>v) return;
	pst[i2].v = pst[i1].v + 1;
	if (s == e) return;
	int m = (s + e) >> 1;
	if (v <= m)
	{
		if (pst[i2].l == 0 || pst[i2].l == pst[i1].l)
		{
			pst[i2].l = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].r == 0) pst[i2].r = pst[i1].r;
		u(pst[i1].l, pst[i2].l, v, s, m);
	}
	else
	{
		if (pst[i2].r == 0 || pst[i2].r == pst[i1].r)
		{
			pst[i2].r = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].l == 0) pst[i2].l = pst[i1].l;
		u(pst[i1].r, pst[i2].r, v, m + 1, e);
	}
}

int q(int i1, int i2, int l, int r, int s, int e)
{
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return pst[i2].v - pst[i1].v;
	int m = (s + e) >> 1;
	return q(pst[i1].l, pst[i2].l, l, r, s, m) + q(pst[i1].r, pst[i2].r, l, r, m + 1, e);
}