#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Pst
{
	int l, r, v;
	Pst() : l(0), r(0), v(0) {}
};

int n, m;
vector<Pst> pst;

void update(int b, lli i, int p, lli s = 0, lli e = 2e9);
lli query(int x1, int x2, int k, lli s = 0, lli e = 2e9);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	pst.resize(n + 1);
	for(int i=1;i<=n;++i)
	{
		lli t;
		cin >> t;
		update(i - 1, t+1e9, i);
	}
	for(int i=0;i<m;++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << query(a-1, b, c)-(lli)1e9<<"\n";
	}
}

void update(int b, lli i, int p, lli s, lli e)
{
	lli m = (s + e) >> 1;
	if(s==e)
	{
		pst[p].v = pst[b].v + 1;
		return;
	}
	if(i<=m)
	{
		if(pst[p].l==0 || pst[p].l==pst[b].l)
		{
			pst[p].l = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[p].r == 0)
			pst[p].r = pst[b].r;
		update(pst[b].l, i, pst[p].l, s, m);
	}
	else
	{
		if(pst[p].r==0 || pst[p].r==pst[b].r)
		{
			pst[p].r = pst.size();
			pst.emplace_back(Pst());
		}
		if (pst[p].l == 0)
			pst[p].l = pst[b].l;
		update(pst[b].r, i, pst[p].r, m + 1, e);
	}
	pst[p].v = pst[pst[p].l].v + pst[pst[p].r].v;
}

lli query(int x1, int x2, int k, lli s, lli e)
{
	if (s == e) 
		return s;
	lli m = (s + e) >> 1;
	if(pst[pst[x2].l].v - pst[pst[x1].l].v >=k)
	{
		return query(pst[x1].l, pst[x2].l, k, s, m);
	}
	else
	{
		return query(pst[x1].r, pst[x2].r, k - pst[pst[x2].l].v + pst[pst[x1].l].v, m + 1, e);
	}
}