#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, p[210];

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
		for (int j = 1; j <= N; ++j)
		{
			int t; cin >> t;
			if (t) m(i, j);
		}
	}
	int u; cin >> u;
	for (int i = 1; i < M; ++i)
	{
		int v; cin >> v;
		if (f(u) != f(v)) { cout << "NO"; return 0; }
	}
	cout << "YES";
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v)
{
	u = f(u), v = f(v);
	if (u == v) return;
	p[u] += p[v];
	p[v] = u;
}