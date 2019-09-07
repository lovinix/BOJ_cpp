#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 20'010, bias = 10'000, msb = 1 << 31;
int N, M, n[MAX], f[MAX], scc[MAX], v[MAX], cnt, sccsz;
vector<int> adj[MAX];
vector<int> stk;

inline int nt(int x);
int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int x, y; 
		cin >> x >> y;
		x = abs(x) + ((x & msb) ? bias : 0);
		y = abs(y) + ((y & msb) ? bias : 0);
		adj[nt(x)].emplace_back(y);
		adj[nt(y)].emplace_back(x);
	}
	for (int i = 1; i <= M; ++i)
	{
		if (!n[i]) dfs(i);
		if (!n[nt(i)]) dfs(nt(i));
	}
	for (int i = 1; i <= M; ++i)
	{
		if (scc[i] == scc[nt(i)])
		{
			cout << "OTL"; return 0;
		}
	}
	cout << "^_^";
}

inline int nt(int x)
{
	return x > bias ? x - bias : x + bias;
}

int dfs(int u)
{
	n[u] = ++cnt;
	int ret = n[u];
	stk.push_back(u);
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
			f[c] = 1;
			stk.pop_back();
			scc[c] = sccsz;
			if (c == u) { ++sccsz; break; }
		}
	}
	return ret;
}