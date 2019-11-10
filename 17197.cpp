#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, p[100'010];
set<pii> g[100'010];

int f(int u);
void m(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(p, -1, sizeof p);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int x, y;
		cin >> x >> y;
		g[i].emplace(x, y);
	}
	for (int i = 1; i <= M; ++i)
	{
		int u, v;
		cin >> u >> v;
		m(u, v);
	}
	int ans = INT_MAX;
	for (int i = 1; i <= N; ++i)
	{
		if (p[i] > 0) continue;
		int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
		for (auto& [x, y] : g[i])
		{
			minx = min(minx, x);
			miny = min(miny, y);
			maxx = max(maxx, x);
			maxy = max(maxy, y);
		}
		int cur = 2 * (maxx - minx + maxy - miny);
		ans = min(ans, cur);
	}
	cout << ans;
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v)
{
	u = f(u), v = f(v);
	if (u == v) return;
	if (p[u] > p[v]) swap(u, v);
	for (auto& c : g[v]) g[u].emplace(c);
	p[v] = u;
	p[u] = -1 * g[u].size();
}