#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, p[1'000'010];

int f(int u);
void m(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(p, -1, sizeof p);
	cin >> N;
	while (N--)
	{
		char c;
		int a, b;
		cin >> c;
		if (c == 'I')
		{
			cin >> a >> b;
			m(a, b);
		}
		else
		{
			cin >> a;
			cout << -p[f(a)] << "\n";
		}
	}

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