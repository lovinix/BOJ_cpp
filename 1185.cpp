#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;
using lli = long long;

int N, P, arr[10'010], p[10'010], cnt, mn = 123456789;
lli ans;
tu edge[100'010];

int f(int u);
void m(int u, int v, int w);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(p, -1, sizeof p);
	cin >> N >> P;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		mn = min(arr[i], mn);
	}
	for (int i = 0; i < P; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge[i] = { u,v,2 * w + arr[u] + arr[v] };
	}
	sort(edge, edge + P, [](tu& t1, tu& t2) {return get<2>(t1) < get<2>(t2); });
	for (int i = 0; cnt < N - 1; ++i)
	{
		auto& [u, v, w] = edge[i];
		m(u, v, w);
	}
	cout << ans + mn;
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v, int w)
{
	u = f(u), v = f(v);
	if (u == v) return;
	p[u] += p[v];
	p[v] = u;
	++cnt;
	ans += w;
}