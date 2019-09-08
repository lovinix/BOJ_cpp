#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define first X
#define second Y
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pll = pair<lli, lli>;
using tu = pair<int, pll>;

const int MAX = 2'010, bias = 1000;
int W, P, scc[MAX], n[MAX], f[MAX], cnt, sccnum;
pll w[MAX];
tu p[MAX];
vector<int> adj[MAX];
vector<int> stk;

inline int ccw(pll& p1, pll& p2, pll& p3);
int iscross(pll p1, pll p2, pll p3, pll p4);
inline int nt(int x);
int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> W >> P;
	for (int i = 1; i <= W; ++i)
		cin >> w[i].X >> w[i].Y;
	for (int i = 1; i <= P; ++i)
	{
		cin >> p[i].X >> p[i].Y.X >> p[i].Y.Y;
		for (int k = 1; k < i; ++k)
		{
			if (p[i].X == p[k].X) continue;
			if (iscross(w[p[i].X], p[i].Y, w[p[k].X], p[k].Y))
			{
				adj[i].emplace_back(nt(k));
				adj[k].emplace_back(nt(i));
				adj[nt(i)].emplace_back(k);
				adj[nt(k)].emplace_back(i);
			}
		}
	}
	for (int i = 1; i <= P; ++i)
	{
		if (!n[i]) dfs(i);
		if (!n[nt(i)]) dfs(nt(i));
	}
	for (int i = 1; i <= P; ++i)
	{
		if (scc[i] == scc[nt(i)])
		{
			cout << "impossible"; return 0;
		}
	}
	cout << "possible";
}

inline int ccw(pll& p1, pll& p2, pll& p3)
{
	lli t = p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y - p2.X * p1.Y - p3.X * p2.Y - p1.X * p3.Y;
	return t < 0 ? -1 : t>0;
}

int iscross(pll p1, pll p2, pll p3, pll p4)
{
	int f1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int f2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
	if (f1 == 0 && f2 == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return p1 <= p4 && p3 <= p2;
	}
	return f1 <= 0 && f2 <= 0;
}

inline int nt(int x)
{
	return x > bias ? x - bias : x + bias;
}


int dfs(int u)
{
	n[u] = ++cnt;
	int ret = n[u];
	stk.emplace_back(u);
	for (auto& v : adj[u])
	{
		if (!n[v]) ret = min(ret, dfs(v));
		else if (!f[v]) ret = min(ret, n[v]);
	}
	if (ret == n[u])
	{
		while (1)
		{
			int c = stk[stk.size() - 1];
			stk.pop_back();
			f[c] = 1;
			scc[c] = sccnum;
			if (c == u) { ++sccnum; break; }
		}
	}
	return ret;
}