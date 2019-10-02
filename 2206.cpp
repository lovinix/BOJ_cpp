#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int, int>;

int N, M, v[1010][1010][2], dn[] = { -1,1,0,0 }, dm[] = { 0,0,1,-1 };
string arr[1010];
queue<tu> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
			cin >> arr[i];
	q.emplace(0, 0, 1, 1);
	while (!q.empty())
	{
		auto [n, m, c, d] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nn = n + dn[i], nm = m + dm[i], nc = c;
			if (nn < 0 || nm < 0 || nn >= N || nm >= M) continue;
			if (v[nn][nm][nc]) continue;
			if (arr[nn][nm]=='1')
			{
				if (nc && !v[nn][nm][nc - 1])
				{
					v[nn][nm][nc - 1] = 1;
					q.emplace(nn, nm, nc - 1, d + 1);
				}
				continue;
			}
			if (nn == N - 1 && nm == M - 1)
			{
				cout << d + 1; return 0;
			}
			v[nn][nm][nc] = 1;
			q.emplace(nn, nm, nc, d + 1);
		}
	}
	cout << -1;
}
