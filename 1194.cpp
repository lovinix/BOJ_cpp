#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int, int>;

int N, M, dn[] = { -1,1,0,0 }, dm[] = { 0,0,1,-1 }, visit[51][51][1<<6];
string arr[51];
queue<tu> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		for (int j = 0; j < M; ++j)
			if (arr[i][j] == '0') q.emplace(i, j, 0, 0);
	}
	while (!q.empty())
	{
		auto [n, m, st, d] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nn = n + dn[i], nm = m + dm[i], nst = st;
			if (nn < 0 || nm < 0 || nn >= N || nm >= M) continue;
			char next = arr[nn][nm];
			if (next == '#') continue;
			if (visit[nn][nm][st]) continue;
			if (next == '1') { cout << d + 1; return 0; }
			if (next >= 'A' && next <= 'F' && !(st & 1 << next - 'A')) continue;
			if (next >= 'a' && next <= 'f') nst |= 1 << next - 'a';
			visit[nn][nm][st] = 1;
			q.emplace(nn, nm, nst, d + 1);
		}
	}
	cout << -1;
}