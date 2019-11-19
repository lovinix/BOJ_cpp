#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

int M, N, v[110][110], dn[] = { -1,1,0,0 }, dm[] = { 0,0,-1,1 };
string arr[110];
queue<tu> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(v, 0x3f, sizeof v);
	cin >> M >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	q.emplace(0, 0, 0);
	while (!q.empty())
	{
		auto [n, m, d] = q.front();
		q.pop();
		if (n == N - 1 && m == M - 1) continue;
		for (int i = 0; i < 4; ++i)
		{
			int nn = n + dn[i], nm = m + dm[i], nd = d + arr[nn][nm] - '0';
			if (nn < 0 || nn >= N || nm < 0 || nm >= M) continue;
			if (v[nn][nm] <= nd) continue;
			q.emplace(nn, nm, nd);
			v[nn][nm] = nd;
		}
	}
	cout << v[N - 1][M - 1];
}