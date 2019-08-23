#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

struct Pst
{
	int l, r, v;
	Pst() : l(0), r(0), v(0) {}
};

int T, N, M;
lli ans;
vector<Pst> pst;
vector<pii> qu;

void u(int i1, int i2, int v, int s = 0, int e = 1e5 + 1);
lli q(int i1, int i2, int l, int r, int s = 0, int e = 1e5 + 1);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		pst.clear();
		qu.clear();
		ans = 0;
		pst.resize(1e5 + 2);
		for(int i=0;i<N;++i)
		{
			int x, y;
			cin >> x >> y;
			qu.emplace_back(x + 1, y);
		}
		sort(qu.begin(), qu.end());
		for(int i=1,j=0;i<=1e5+1;++i)
		{
			pst[i] = pst[i - 1];
			while(j<qu.size() && qu[j].first==i)
			{
				u(i - 1, i, qu[j].second);
				++j;
			}
		}
		while(M--)
		{
			int l, r, b, t;
			cin >> l >> r >> b >> t;
			ans += q(l, r + 1, b, t);
		}
		cout << ans << "\n";
	}
}

void u(int i1, int i2, int v, int s, int e)
{
	if (v < s || e < v) return;
	pst[i2].v = pst[i2].v == 0 ? pst[i1].v + 1 : pst[i2].v + 1;
	if (s == e) return;
	int m = (s + e) >> 1;
	if(v<=m)
	{
		if(pst[i2].l==0 || pst[i2].l == pst[i1].l)
		{
			pst[i2].l = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].r == 0) pst[i2].r = pst[i1].r;
		u(pst[i1].l, pst[i2].l, v, s, m);
	}
	else
	{
		if(pst[i2].r==0 || pst[i2].r == pst[i1].r)
		{
			pst[i2].r = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].l == 0) pst[i2].l = pst[i1].l;
		u(pst[i1].r, pst[i2].r, v, m + 1, e);
	}
}

lli q(int i1, int i2, int l, int r, int s, int e)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return pst[i2].v - pst[i1].v;
	int m = (s + e) >> 1;
	return q(pst[i1].l, pst[i2].l, l, r, s, m) + q(pst[i1].r, pst[i2].r, l, r, m + 1, e);
}