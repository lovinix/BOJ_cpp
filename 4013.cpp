#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

constexpr int sz = 500'010;
int N, M, S, P, n[sz], f[sz], scc[sz], cnt, A[sz], R[sz], sR[sz], T[sz], ans[sz], ind[sz];
vector<int> adj[sz], stk, sadj[sz];
queue<pii> q;
set<pii> e;

int dfs(int u, int p)
{
	n[u] = ++cnt;
	int ret = n[u];
	stk.emplace_back(u);
	for (auto& v : adj[u])
	{
		if (!n[v]) ret = min(ret, dfs(v, u));
		else if (!f[v]) { ret = min(ret, n[v]); }
		else e.emplace(u, scc[v]);
	}
	if (ret == n[u])
	{
		while (1)
		{
			int c = stk[stk.size() - 1];
			if (R[c]) sR[u] = 1;
			T[u] += A[c];
			stk.pop_back();
			f[c] = 1;
			scc[c] = u;
			if (c == u) { break; }
		}
		e.emplace(p, u);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
	}
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	cin >> S >> P;
	for (int i = 0; i < P; ++i)
	{
		int p; cin >> p;
		R[p] = 1;
	}
	dfs(S, 0);
	for (auto& [u, v] : e)
	{
		sadj[scc[u]].emplace_back(v);
		ind[v]++;
	}
	q.emplace(scc[S], T[S]);
	if (sR[scc[S]]) ans[scc[S]] = T[S];
	while (!q.empty())
	{
		auto [u, s] = q.front();
		q.pop();
		for (auto& v : sadj[u])
		{
			--ind[v];
			ans[v] = max(ans[v], s + T[v]);
			if (!ind[v]) q.emplace(v, ans[v]);
		}
	}
	int a = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (sR[i]) a = max(a, ans[i]);
	}
	cout << a;
}