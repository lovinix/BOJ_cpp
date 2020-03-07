#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 5010;
char buf[10'000'010];
int N, M, n[sz], f[sz], scc[sz], sccnum, cnt, fl[sz], idx;
vector<int> adj[sz], sadj[sz];
stack<int> stk;

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
	stk.push(u);
	for (auto& v : adj[u])
	{
		if (!n[v]) ret = min(ret, dfs(v));
		else if (!f[v]) ret = min(ret, n[v]);
	}
	if (ret == n[u])
	{
		while (1)
		{
			int c = stk.top();
			stk.pop();
			f[c] = 1;
			scc[c] = sccnum;
			for (auto& v : adj[c])
				sadj[sccnum].emplace_back(v);
			if (c == u) { ++sccnum; break; }
		}
	}
	return ret;
}

int main()
{
	fread(buf, 1, sizeof buf, stdin);
	while (1)
	{
		N = nextInt();
		if (N == 0) return 0;
		M = nextInt();
		for (int i = 0; i <= N; ++i) { adj[i].clear(); sadj[i].clear(); }
		for (auto& v : { n,f,scc }) fill(v, v + N + 1, 0);
		cnt = sccnum = 0;
		for (int i = 0; i < M; ++i)
		{
			int u, v;
			u = nextInt();
			v = nextInt();
			adj[u].emplace_back(v);
		}
		for (int i = 1; i <= N; ++i)
		{
			if (!n[i]) dfs(i);
		}
		memset(fl, -1, sizeof fl);
		for (int i = 1; i <= N; ++i)
		{
			if (fl[scc[i]] == -1)
			{
				for (auto& v : sadj[scc[i]])
					if (scc[i] != scc[v]) { fl[scc[i]] = 0; goto next; }
				fl[scc[i]] = 1;
			}
		next:
			if (fl[scc[i]])
				printf("%d ", i);
		}
		printf("\n");
	}
}