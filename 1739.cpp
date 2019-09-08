#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 4040, bias = 2000;
int T, N, M, K, scc[MAX], n[MAX], f[MAX], cnt, sccnum;
vector<int> adj[MAX], stk;

void add(int rs, int cs, int rd, int cd);
inline int nt(int x);
int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		memset(n, 0, sizeof n);
		memset(f, 0, sizeof f);
		cnt = sccnum = 0;
		for (auto& v : adj) v.clear();
		cin >> N >> M >> K;
		for (int i = 1; i <= K; ++i)
		{
			int rs, cs, rd, cd;
			cin >> rs >> cs >> rd >> cd;
			cs += N; cd += N;
			add(rs, cs, rd, cd);
		}
		for (int i = 1; i <= N + M; ++i)
		{
			if (!n[i]) dfs(i);
			if (!n[nt(i)]) dfs(nt(i));
		}
		for (int i = 1; i <= N + M; ++i)
		{
			if (scc[i] == scc[nt(i)])
			{
				cout << "No\n"; goto next;
			}
		}
		cout << "Yes\n";
	next:;
	}
}

void add(int rs, int cs, int rd, int cd)
{
	if (rs == rd && cs == cd) return;
	if (rs == rd)
	{
		if (cd < cs) rs = nt(rs);
		adj[nt(rs)].emplace_back(rs);
		return;
	}
	if (cs == cd)
	{
		if (rd < rs) cs = nt(cs);
		adj[nt(cs)].emplace_back(cs);
		return;
	}
	if (rd < rs)
	{
		cs = nt(cs); cd = nt(cd);
	}
	if (cd < cs)
	{
		rd = nt(rd); rs = nt(rs);
	}
	adj[nt(rs)].emplace_back(cs);
	adj[nt(cs)].emplace_back(rs);
	adj[nt(cs)].emplace_back(cd);
	adj[nt(cd)].emplace_back(cs);
	adj[nt(rs)].emplace_back(rd);
	adj[nt(rd)].emplace_back(rs);
	adj[nt(cd)].emplace_back(rd);
	adj[nt(rd)].emplace_back(cd);
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