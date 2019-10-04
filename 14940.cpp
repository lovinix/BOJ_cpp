#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

int N, M, arr[1010][1010], dn[] = { -1,1,0,0 }, dm[] = { 0,0,-1,1 };
int v[1010][1010];
queue<tu> q;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2) q.emplace(i, j, 0);
		}
	}
	while (!q.empty())
	{
		auto [n, m, d] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nn = n + dn[i], nm = m + dm[i];
			if (nn < 0 || nn >= N || nm < 0 || nm >= M) continue;
			if (arr[nn][nm] != 1) continue;
			if (v[nn][nm]) continue;
			v[nn][nm] = d + 1;
			q.emplace(nn, nm, d + 1);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << (arr[i][j] == 1 && v[i][j] == 0 ? -1 : v[i][j]) << " ";
		}
		cout << "\n";
	}
		
}