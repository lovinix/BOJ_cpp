#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int>;

struct Query { int l, r, m, n; };

constexpr int sz = 100'010;
int N, K, nl[sz], nr[sz], cnt, mx, ans[sz], sr[sz], Z;
lli J, fw[sz];
vector<int> adj[sz], vt[sz];
tu A[sz];
Query query[sz];

void dfs(int u, int p)
{
	nl[u] = ++cnt;
	for (auto& v : adj[u])
	{
		if (v == p) continue;
		dfs(v, u);
	}
	nr[u] = cnt;
}

void fu(int i, int v)
{
	while (i <= N)
	{
		fw[i] += v;
		i += i & -i;
	}
}

lli fq(int i)
{
	lli ret = 0;
	while (i)
	{
		ret += fw[i];
		i -= i & -i;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(ans, -1, sizeof ans);
	cin >> N >> K >> J;
	for (int i = 2; i <= N; ++i)
	{
		int p; cin >> p;
		adj[p].emplace_back(i);
	}
	for (int i = 1; i <= N; ++i)
	{
		int v; cin >> v;
		vt[v].emplace_back(i);
		sr[i] = v;
	}
	dfs(1, 0);
	for (int i = 0; i < K; ++i)
	{
		auto& [t, p, s] = A[i];
		cin >> t >> p >> s;
		s /= nr[p] - nl[p] + 1;
		mx = max(mx, t);
	}
	sort(A, A + K);
	for (int i = 1; i <= N; ++i)
	{
		if (vt[i].size() == 0) continue;
		auto& [l, r, m, n] = query[Z++];
		l = 0, r = mx, m = l + r >> 1, n = i;
	}
	while (1)
	{
		int idx = 0, fl = 0;
		for (int i = 0; i < Z; ++i)
		{
			auto& [l, r, m, n] = query[i];
			while (idx < K && get<0>(A[idx]) <= m)
			{
				auto& [t, p, s] = A[idx++];
				fu(nl[p], s);
				fu(nr[p] + 1, -s);
			}
			lli tot = 0;
			for (auto& j : vt[n]) { tot += fq(nl[j]); }
			if (tot > J * vt[n].size()) { r = m - 1; ans[n] = m; }
			else l = m + 1;
			m = l + r >> 1;
			if (l <= r) fl = 1;
		}
		if (fl == 0) break;
		memset(fw, 0, sizeof fw);
		sort(query, query + Z, [](Query& q1, Query& q2) {return q1.m < q2.m; });
	}
	for (int i = 1; i <= N; ++i)
		cout << ans[sr[i]] << "\n";
	
}