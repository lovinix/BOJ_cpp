#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

const int MAX = 800'000, bias = 400'000;
int N, scc[MAX], n[MAX], f[MAX], tf[200'000], cnt, sccnum, mx;
pii fr[200'001][2];
vector<int> adj[MAX], stk, fn;

inline int nt(int x);
int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> fr[i][0].X >> fr[i][0].Y >> fr[i][1].X >> fr[i][1].Y;
		fn.emplace_back(fr[i][0].X);
		fn.emplace_back(fr[i][1].X);
		if (!tf[fr[i][0].X]) tf[fr[i][0].X] = i;
		if (!tf[fr[i][1].X]) tf[fr[i][1].X] = i;
		mx = max({ mx, fr[i][0].Y, fr[i][0].Y });
	}
	sort(fn.begin(), fn.end());
	fn.erase(unique(fn.begin(), fn.end()), fn.end());
	int l = 0, r = mx;
	int ans = 1'000'001;
	while (l <= r)
	{
		int m = l + r >> 1;
		for (auto& v : adj) v.clear();
		memset(n, 0, sizeof n);
		memset(f, 0, sizeof f);
		cnt = sccnum = 0;
		for (int i = 1; i <= N; ++i)
		{
			int a = fr[i][0].X, b = fr[i][1].X;
			if (tf[a] != i) a = nt(a);
			if (tf[b] != i) b = nt(b);
			if (fr[i][0].Y <= m && fr[i][1].Y <= m)
			{
				adj[a].emplace_back(nt(b));
				adj[b].emplace_back(nt(a));
				adj[nt(a)].emplace_back(b);
				adj[nt(b)].emplace_back(a);
			}
			else if (fr[i][0].Y <= m)
			{
				adj[nt(a)].emplace_back(a);
			}
			else if (fr[i][1].Y <= m)
			{
				adj[nt(b)].emplace_back(b);
			}
			else
			{
				l = m + 1;
				goto next;
			}
		}
		for (auto& i : fn)
		{
			if (!n[i]) dfs(i);
			if (!n[nt(i)]) dfs(nt(i));
		}
		for (auto& i : fn)
		{
			if (scc[i] == scc[nt(i)])
			{
				l = m + 1;
				goto next;
			}
		}
		ans = m;
		r = m - 1;
	next:;
	}
	cout << (ans == 1'000'001 ? -1 : ans);
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