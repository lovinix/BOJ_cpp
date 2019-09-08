#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200'010, bias = 100'000;
int N, M, scc[MAX], n[MAX], f[MAX], cnt, sccnum, state[MAX];
vector<int> room[MAX];
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
		cin >> state[i];
	}
	for (int i = 1; i <= M; ++i)
	{
		int k; cin >> k;
		while (k--)
		{
			int n; cin >> n;
			room[n].emplace_back(i);
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		int x = room[i][0], y = room[i][1];
		if (state[i])
		{
			adj[nt(y)].emplace_back(nt(x));
			adj[x].emplace_back(y);
			adj[nt(x)].emplace_back(nt(y));
			adj[y].emplace_back(x);
		}
		else
		{
			adj[x].emplace_back(nt(y));
			adj[y].emplace_back(nt(x));
			adj[nt(x)].emplace_back(y);
			adj[nt(y)].emplace_back(x);
		}
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
			cout << 0; return 0;
		}
	}
	cout << 1;
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