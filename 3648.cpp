#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2020, bias = 1000, msb=1<<31;
int N, M, scc[MAX], v[MAX], f[MAX], cnt, n[MAX], sccnum;
vector<int> adj[MAX];
vector<int> stk;

inline int nt(int x);
int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (cin >> N >> M)
	{
		for (int i = 1; i <= MAX; ++i)
			adj[i].clear();
		memset(v, 0, sizeof v);
		memset(f, 0, sizeof f);
		memset(n, 0, sizeof n);
		sccnum = cnt = 0;
		for (int i = 1; i <= M; ++i)
		{
			int x, y;
			cin >> x >> y;
			x = abs(x) + ((x & msb) ? bias : 0);
			y = abs(y) + ((y & msb) ? bias : 0);
			adj[nt(x)].emplace_back(y);
			adj[nt(y)].emplace_back(x);
		}
		adj[nt(1)].emplace_back(1);
		for (int i = 1; i <= N; ++i)
		{
			if (!n[i]) dfs(i);
			if (!n[nt(i)]) dfs(nt(i));
		}
		for (int i = 1; i <= N; ++i)
		{
			if (scc[i] == scc[nt(i)])
			{
				cout << "no\n";
				goto end;
			}
		}
		cout << "yes\n";
	end:;
	}
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