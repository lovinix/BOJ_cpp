#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

int N, M, uf[100'010], mx;
tu E[1'000'010];

int f(int u)
{
	return uf[u] < 0 ? u : uf[u] = f(uf[u]);
}

int m(int u, int v)
{
	u = f(u), v = f(v);
	if (u == v) return 0;
	uf[u] += uf[v];
	uf[v] = u;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(uf, -1, sizeof uf);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		auto& [d, u, v] = E[i];
		cin >> u >> v >> d;
	}
	sort(E, E + M);
	int ans = 0;
	for (int i = 0; i < M; ++i)
	{
		auto& [d, u, v] = E[i];
		if (m(u, v)) { ans += d; mx = max(mx, d); }
	}
	cout << ans - mx;
}