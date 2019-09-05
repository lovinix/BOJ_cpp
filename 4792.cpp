#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

int N, M, K, mn, mx, p[1010], e;
tu arr[1010*1010];

int f(int u);
void m(tu& t, int flag);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (cin >> N >> M >> K)
	{
		if (N == 0 && M == 0 && K == 0) return 0;
		mn = 0, mx = 0;
		for (int i = 0; i < M; ++i)
		{
			char c; int f, t;
			cin >> c >> f >> t;
			arr[i] = { f,t,(c == 'B' ? 1 : 0) };
		}
		memset(p, -1, sizeof p);
		e = 0;
		sort(arr, arr + M, [](tu& t1, tu& t2) {return get<2>(t1) < get<2>(t2); });
		for (int i = 0; e < N-1; ++i)
			m(arr[i], 0);
		memset(p, -1, sizeof p);
		e = 0;
		sort(arr, arr + M, [](tu& t1, tu& t2) {return get<2>(t1) > get<2>(t2); });
		for (int i = 0; e < N-1; ++i)
			m(arr[i], 1);
		if (mn <= K && K <= mx) cout << "1\n";
		else cout << "0\n";
	}
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(tu& t, int flag)
{
	auto [u, v, c] = t;
	u = f(u); v = f(v);
	if (u == v) return;
	p[u] += p[v];
	p[v] = u;
	++e;
	if (flag && c) mx++;
	else if (!flag && c) mn++;
}
