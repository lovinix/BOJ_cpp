#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int, int>;

int N, M, T, arr[110][110], v[110][110][2], dn[] = { -1,1,0,0 }, dm[] = { 0,0,-1,1 };
queue<tu> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	q.emplace(0, 0, 0, 0);
	while (!q.empty())
	{
		auto [n, m, d, f] = q.front();
		if (d == T) break;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nn = n + dn[i], nm = m + dm[i];
			if (nn < 0 || nn >= N || nm < 0 || nm >= M) continue;
			if (v[nn][nm][f]) continue;
			if (arr[nn][nm] == 1 && f == 0) continue;
			if (nn == N - 1 && nm == M - 1) { cout << d + 1; return 0; }
			v[nn][nm][f] = 1;
			q.emplace(nn, nm, d + 1, f+(arr[nn][nm]==2?1:0));
		}
	}
	cout << "Fail";
}