#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 4040, bias = 2000;
int N, M, cnt, sccnum, scc[MAX], n[MAX], f[MAX];
vector<int> adj[MAX];
vector<int> stk;
string tmp;

inline int nt(int x);
int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		for (int j = 0; j < M; ++j)
		{
			if (tmp[j] == '#')
			{
				adj[nt(i)].emplace_back(nt(N + j));
				adj[N + j].emplace_back(i);
				adj[i].emplace_back(N + j);
				adj[nt(N + j)].emplace_back(nt(i));
			}
			else if (tmp[j] == '*')
			{
				adj[nt(i)].emplace_back(N + j);
				adj[nt(N + j)].emplace_back(i);
				adj[i].emplace_back(nt(N + j));
				adj[N + j].emplace_back(nt(i));
			}
		}
	}
	for (int i = 0; i < N + M; ++i)
	{
		if (!n[i]) dfs(i);
		if (!n[nt(i)]) dfs(nt(i));
	}
	for (int i = 0; i < N + M; ++i)
	{
		if (scc[i] == scc[nt(i)])
		{
			cout << 0; return 0;
		}
	}
	cout << 1;
}

inline int nt(int x)
{
	return x >= bias ? x - bias : x + bias;
}

int dfs(int u)
{
	n[u] = ++cnt;
	stk.emplace_back(u);
	int ret = n[u];
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