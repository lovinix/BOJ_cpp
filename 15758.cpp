#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 100'010;
char buf[10'000'010];
int N, M, n[sz], f[sz], scc[sz], ind[sz], cnt, sccnum, sccsz, idx;
vector<int> adj[sz], stk, query[sz];
priority_queue<int, vector<int>, greater<>> pq;

inline int nextInt()
{
	int ret = 0;
	while (buf[idx] != '\n' && buf[idx] != ' ' && buf[idx] != 0) ret = ret * 10 + buf[idx++] - '0';
	while (buf[idx] == '\n' || buf[idx] == ' ') ++idx;
	return ret;
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
		int t = 0;
		while (1)
		{
			int c = stk[stk.size() - 1];
			stk.pop_back();
			f[c] = 1;
			scc[c] = sccnum;
			for (auto& v : adj[c]) ind[v]++;
			++t;
			if (c == u) { ++sccnum; break; }
		}
		sccsz = max(sccsz, t);
	}
	return ret;
}

int main()
{
	fread(buf, 1, sizeof buf, stdin);
	N = nextInt();
	M = nextInt();
	for (int i = 0; i < M; ++i)
	{
		int c = nextInt();
		for (int j = 0; j < c; ++j)
		{
			int v = nextInt();
			query[i].emplace_back(v);
		}
	}
	int l = 0, r = M, ans = 0;
	while (l <= r)
	{
		for (int i = 0; i <= N; ++i) adj[i].clear();
		for (auto& vt : { n,f,scc,ind }) fill(vt, vt + N + 1, 0);
		cnt = sccnum = sccsz = 0;
		int m = l + r >> 1;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < query[i].size() - 1; ++j)
			{
				adj[query[i][j]].emplace_back(query[i][j + 1]);
			}
		}
		for (int i = 1; i <= N; ++i)
		{
			if (!n[i]) dfs(i);
			if (sccsz > 1) { r = m - 1; goto next; }
		}
		l = m + 1;
		ans = m;
	next:;
	}
	for (int i = 0; i <= N; ++i) adj[i].clear();
	for (auto& vt : { n,f,scc,ind }) fill(vt, vt + N + 1, 0);
	cnt = sccnum = sccsz = 0;
	for (int i = 0; i < ans; ++i)
	{
		for (int j = 0; j < query[i].size() - 1; ++j)
		{
			adj[query[i][j]].emplace_back(query[i][j + 1]);
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!n[i]) dfs(i);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (ind[i] == 0) pq.emplace(i);
	}
	while (!pq.empty())
	{
		int u = pq.top();
		pq.pop();
		printf("%d ", u);
		for (auto& v : adj[u])
		{
			if (--ind[v] == 0) pq.emplace(v);
		}
	}
}