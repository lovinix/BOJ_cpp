#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int>;

int N, M, MOD = 1e9, p[100'010];
lli tot, ans;
auto cmp = [](tu& t1, tu& t2) {return get<2>(t1) < get<2>(t2); };
priority_queue<tu, vector<tu>, decltype(cmp)> pq(cmp);

int f(int u);
void m(int u, int v, int w);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(p, -1, sizeof p);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;
		pq.emplace(x, y, w);
		tot += w;
	}
	while (!pq.empty())
	{
		auto [u, v, w] = pq.top();
		pq.pop();
		m(u, v, w);
	}
	cout << ans;
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v, int w)
{
	u = f(u); v = f(v);
	if (u == v) { tot -= w; return; }
	ans = (ans + ((1LL * -p[u] * -p[v]) % MOD) * tot) % MOD;
	p[u] += p[v];
	p[v] = u;
	tot -= w;
}