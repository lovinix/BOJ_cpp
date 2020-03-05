#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct tu { int id, v[3]; };

int N, uf[100'010];
tu A[100'010];
vector<tuple<int, int, int>> E;

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
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		auto& [id, v] = A[i];
		cin >> v[0] >> v[1] >> v[2];
		id = i;
	}
	for (int i = 0; i < 3; ++i)
	{
		sort(A, A + N, [&](tu& t1, tu& t2) {return t1.v[i] < t2.v[i]; });
		for (int j = 0; j < N - 1; ++j)
		{
			auto& [id1, v1] = A[j];
			auto& [id2, v2] = A[j + 1];
			E.emplace_back(abs(v1[i] - v2[i]), id1, id2);
		}
	}
	sort(E.begin(), E.end());
	lli ans = 0;
	for (auto& [d, u, v] : E)
	{
		if (m(u, v)) ans += d;
	}
	cout << ans;
}