#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Pst
{
	int l, r, v;
	Pst() : l(0), r(0), v(0) {}
};

int M, cnt, MAX = (1<<19)-1;
vector<Pst> pst;

void u(int i1, int i2, int v, int s = 0, int e = MAX);
int kth(int i1, int i2, int k, int s = 0, int e = MAX);
int lo(int i1, int i2, int x, int s = 0, int e = MAX);
int xo(int i1, int i2, int x, int sh = 18, int s = 0, int e = MAX);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> M;
	pst.resize(M + 1);
	while(M--)
	{
		int f, l, r, k, x;
		cin >> f;
		switch(f)
		{
		case 1:
			cin >> x;
			u(cnt, cnt + 1, x);
			++cnt;
			break;
		case 2:
			cin >> l >> r >> x;
			cout << xo(l - 1, r, x) << "\n";
			break;
		case 3:
			cin >> k;
			for(int i=0;i<k;++i)
				pst[cnt--] = Pst();
			break;
		case 4:
			cin >> l >> r >> x;
			cout << lo(l - 1, r, x) << "\n";
			break;
		case 5:
			cin >> l >> r >> k;
			cout << kth(l - 1, r, k) << "\n";
		}
	}
}

void u(int i1, int i2, int v, int s, int e)
{
	if (v < s || e < v) return;
	pst[i2].v = pst[i1].v+1;
	if (s == e) return;
	int m = (s + e) >> 1;
	if(v<=m)
	{
		if(pst[i2].l==0 || pst[i1].l== pst[i2].l)
		{
			pst[i2].l = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].r == 0) pst[i2].r = pst[i1].r;
		u(pst[i1].l, pst[i2].l, v, s, m);
	}
	else
	{
		if(pst[i2].r==0 || pst[i1].r ==pst[i2].r)
		{
			pst[i2].r = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[i2].l == 0) pst[i2].l = pst[i1].l;
		u(pst[i1].r, pst[i2].r, v, m + 1, e);
	}
}

int kth(int i1, int i2, int k, int s, int e)
{
	if (s == e) return s;
	int m = (s + e) >> 1;
	if (pst[pst[i2].l].v - pst[pst[i1].l].v >= k)
		return kth(pst[i1].l, pst[i2].l, k, s, m);
	else
		return kth(pst[i1].r, pst[i2].r, k - (pst[pst[i2].l].v - pst[pst[i1].l].v), m + 1, e);
}

int lo(int i1, int i2, int x, int s, int e)
{
	if (x < s) return 0;
	if (e <= x) return pst[i2].v - pst[i1].v;
	int m = (s + e) >> 1;
	if (x <= m)
		return lo(pst[i1].l, pst[i2].l, x, s, m);
	else
		return pst[pst[i2].l].v - pst[pst[i1].l].v + lo(pst[i1].r, pst[i2].r, x, m + 1, e);
}

int xo(int i1, int i2, int x, int sh, int s, int e)
{
	if (s == e) return s;
	int m = (s + e) >> 1;
	if ((pst[pst[i2].r].v - pst[pst[i1].r].v)==0 || ( pst[pst[i2].l].v-pst[pst[i1].l].v && (1 << sh & x)))
		return xo(pst[i1].l, pst[i2].l, x, sh - 1, s, m);
	else
		return xo(pst[i1].r, pst[i2].r, x, sh - 1, m + 1, e);
}