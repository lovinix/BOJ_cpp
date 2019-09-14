#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, k, p[10'010], cnt, sum, c[10'010], v[10'010];
pii arr[10'010];

int f(int u);
void m(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(p, -1, sizeof p);
	cin >> N >> M >> k;
	for (int i = 1; i <= N; ++i)
		cin >> c[i];
	for (int i = 0; i < M; ++i)
	{
		int u, v; cin >> u >> v;
		m(u, v);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (v[f(i)] == 1) continue;
		sum += c[f(i)];
		v[f(i)] = 1;
	}
	if (sum > k) cout << "Oh no";
	else cout << sum;
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v)
{
	u = f(u); v = f(v);
	if (u == v) return;
	++cnt;
	p[u] += p[v];
	p[v] = u;
	c[u] = min(c[u], c[v]);
}