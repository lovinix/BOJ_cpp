#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = pair<tuple<int, int, int>,int>;

int N, M, K, mn, mx, p[1010], e;
tu arr[1010 * 1010];

int f(int u);
void m(tu& t, int flag);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i)
	{
		char c; int f, t;
		cin >> c >> f >> t;
		arr[i] = { {f,t,(c == 'B' ? 1 : 0)},0 };
	}
	memset(p, -1, sizeof p);
	e = 0;
	sort(arr, arr + M, [](tu& t1, tu& t2) {return get<2>(t1.first) < get<2>(t2.first); });
	for (int i = 0; e < N - 1; ++i)
		m(arr[i], 0);
	memset(p, -1, sizeof p);
	e = 0;
	sort(arr, arr + M, [](tu& t1, tu& t2) {return get<2>(t2.first) < get<2>(t1.first); });
	for (int i = 0; e < N - 1; ++i)
		m(arr[i], 1);
	if (mn <= K && K <= mx) 
	{
		memset(p, -1, sizeof p);
		e = 0, mx = 0;
		for (int i = 0; e < N - 1; ++i)
		{
			auto& [u, v, c] = arr[i].first;
			if (arr[i].second == 2)
			{
				m(arr[i], 2);
			}
			else if (mx < K)
			{
				m(arr[i], 2);
			}
			else if (get<2>(arr[i].first) == 0)
			{
				m(arr[i], 2);
			}
		}
	}
	else cout << 0;

}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(tu& t, int flag)
{
	auto [u, v, c] = t.first;
	u = f(u); v = f(v);
	if (u == v) return;
	p[u] += p[v];
	p[v] = u;
	++e;
	t.second++;
	if (flag && c) mx++;
	else if (!flag && c) mn++;
	if (flag == 2)
	{
		auto& [a, b, c] = t.first;
		cout << a << " " << b << "\n";
	}
}
