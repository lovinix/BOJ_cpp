#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pli = pair<lli, int>;
using tu = tuple<int, int, int>;

int N, M, C, vst[100'010], V[100'010];
lli S[100'010], D[100'010], PS[100'010];
tu E[200'010];
vector<pli> adj[100'010];
priority_queue<pli,vector<pli>,greater<pli>> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> C;
	for (int i = 0; i < M; ++i)
	{
		int u, v, d;
		cin >> u >> v >> d;
		E[i] = { u,v,d };
		adj[u].emplace_back(v, d);
		adj[v].emplace_back(u, d);
	}
	memset(D, 0x3f, sizeof D);
	D[1] = 0;
	pq.emplace(0, 1);
	while (!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if (vst[u]) continue;
		for (auto& [v, e] : adj[u])
		{
			if (D[v] > d + e) { D[v] = d + e; pq.emplace(D[v], v); }
		}
		vst[u] = 1;
	}
	iota(V + 1, V + N + 1, 1);
	sort(V + 1, V + N + 1, [&](int& u, int& v) {return D[u] < D[v]; });
	for (int i = 0; i < M; ++i)
	{
		auto& [u, v, d] = E[i];
		S[D[u] > D[v] ? u : v] += d;
	}
	for (int i = 1; i <= N; ++i)
		PS[i] = PS[i - 1] + S[V[i]];
	lli ans = LLONG_MAX;
	for (int i = 1; i <= N; ++i)
		ans = min(ans, C * D[V[i]] + (PS[N] - PS[i]));
	cout << ans;
}