#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

char buf[10'000'010];
int N, M, n[50'010], f[50'010], uf[50'010], scc[50'010], cnt, sccnum, idx;
vector<int> adj[50'010], stk;
vector<pii> A;

inline int nextInt()
{
	int ret = 0;
	while (buf[idx] != '\n' && buf[idx] != ' ' && buf[idx] != 0) ret = ret * 10 + buf[idx++] - '0';
	while (buf[idx] == '\n' || buf[idx] == ' ') ++idx;
	return ret;
}

int fnd(int u)
{
	return uf[u] < 0 ? u : uf[u] = fnd(uf[u]);
}

void mg(int u, int v)
{
	u = fnd(u), v = fnd(v);
	if (u == v) return;
	uf[u] += uf[v];
	uf[v] = u;
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
		int cnt = 0;
		while (1)
		{
			int c = stk[stk.size() - 1];
			stk.pop_back();
			f[c] = 1;
			scc[c] = sccnum;
			++cnt;
			if (c == u) { ++sccnum; break; }
		}
		if (cnt > 1) { printf("inconsistent"); exit(0); }
	}
	return ret;
}

int main()
{
	fread(buf, 1, sizeof buf, stdin);
	memset(uf, -1, sizeof uf);
	N = nextInt();
	M = nextInt();
	for (int i = 0; i < M; ++i)
	{
		int u, v; char c;
		u = nextInt();
		c = nextInt() + '0';
		v = nextInt();
		if (c == '=') { mg(u, v); continue; }
		if (c == '<') swap(u, v);
		A.emplace_back(u, v);
	}
	for (auto& [u, v] : A)
	{
		u = fnd(u); v = fnd(v);
		if (u == v) { printf("inconsistent"); return 0; }
		adj[u].emplace_back(v);
	}
	for (int i = 0; i < N; ++i)
	{
		if (!n[i]) dfs(i);
	}
	printf("consistent");
}