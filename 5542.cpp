#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tu = tuple<int, int, int>;

struct Query { int l, r, m, u, v, id; };

constexpr int sz = 100'010;
int N, M, K, Q, vst[sz], dist[sz], uf[sz];
vector<pii> adj[sz];
priority_queue<pii, vector<pii>, greater<pii>> pq;
tu E[2 * sz];
Query query[sz];

int f(int u)
{
	return uf[u] < 0 ? u : uf[u] = f(uf[u]);
}

void mg(int u, int v)
{
	u = f(u), v = f(v);
	if (u == v) return;
	uf[u] += uf[v];
	uf[v] = u;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dist, 0x3f, sizeof dist);
	cin >> N >> M >> K >> Q;
	for (int i = 0; i < M; ++i)
	{
		auto& [w, u, v] = E[i];
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for (int i = 0; i < K; ++i)
	{
		int k; cin >> k;
		dist[k] = 0;
		pq.emplace(0, k);
	}
	while (!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if (vst[u]) continue;
		for (auto& [v, w] : adj[u])
		{
			if (d + w < dist[v]) 
			{ 
				dist[v] = d + w; 
				pq.emplace(dist[v], v); 
			}
		}
		vst[u] = 1;
	}
	for (int i = 0, mx = *max_element(dist + 1, dist + N + 1); i < Q; ++i)
	{
		auto& [l, r, m, u, v, id] = query[i];
		cin >> u >> v;
		r = mx;
		m = l + r >> 1;
		id = i;
	}
	for (int i = 0; i < M; ++i)
	{
		auto& [w, u, v] = E[i];
		w = min(dist[u], dist[v]);
	}
	sort(E, E + M);
	while (1)
	{
		sort(query, query + Q, [](Query& q1, Query& q2) {return q1.m < q2.m; });
		memset(uf, -1, sizeof uf);
		int idx = M - 1, fl = 0;
		for (int i = Q - 1; i >= 0; --i)
		{
			auto& [l, r, m, u, v, id] = query[i];
			while (idx >= 0 && get<0>(E[idx]) >= m)
			{
				auto& [d, x, y] = E[idx];
				mg(x, y);
				--idx;
			}
			if (f(u) == f(v)) { l = m + 1; }
			else { r = m - 1; }
			m = l + r >> 1;
			if (l <= r) fl = 1;
		}
		if (fl == 0) break;
	}
	sort(query, query + Q, [](Query& q1, Query& q2) {return q1.id < q2.id; });
	for (int i = 0; i < Q; ++i)
		cout << query[i].l - 1 << "\n";
}