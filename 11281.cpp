#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int bias = 10'000, MAX = 20'100, msb = 1 << 31;
int N, M, scc[MAX], num[MAX], cnt, visit[MAX], fin[MAX], sccnum, ans[MAX];
vector<int> adj[MAX];
vector<int> stk;
vector<int> lst[MAX];

inline int nt(int x);
int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int x, y;
		cin >> x >> y;
		x = abs(x) + ((x & msb) ? bias : 0);
		y = abs(y) + ((y & msb) ? bias : 0);
		adj[nt(x)].emplace_back(y);
		adj[nt(y)].emplace_back(x);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!num[i]) dfs(i);
		if (!num[nt(i)]) dfs(nt(i));
	}
	for (int i = 1; i <= N; ++i)
	{
		if (scc[i] == scc[nt(i)])
		{
			cout << 0; return 0;
		}
	}
	cout << "1\n";
	memset(ans, -1, sizeof ans);
	for (int i = sccnum - 1; i >= 0; --i)
	{
		for (auto& v : lst[i])
		{
			if (ans[v] == -1)
			{
				ans[v] = 0;
				ans[nt(v)] = 1;
			}
		}
	}
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << " ";
}

inline int nt(int x)
{
	return x > bias ? x - bias : x + bias;
}

int dfs(int u)
{
	num[u] = ++cnt;
	int ret = num[u];
	stk.push_back(u);
	for (auto& v : adj[u])
	{
		if (!num[v]) ret = min(ret, dfs(v));
		else if (!fin[v]) ret = min(ret, num[v]);
	}
	if (ret == num[u])
	{
		while (1)
		{
			int c = stk[stk.size() - 1];
			stk.pop_back();
			fin[c] = 1;
			scc[c] = sccnum;
			lst[sccnum].emplace_back(c);
			if (c == u) { ++sccnum; break; }
		}
	}
	return ret;
}