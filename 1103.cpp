#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

int N, M, vst[51][51][4][10], ans, dn[] = { -1,1,0,0 }, dm[] = { 0,0,1,-1 };
string arr[51];
queue<tu> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	q.emplace(0, 0, 0);
	while (!q.empty())
	{
		auto [n, m, d] = q.front();
		int a = arr[n][m] - '0';
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nn = n + a * dn[i], nm = m + a * dm[i];
			if (nn < 0 || nm < 0 || nn >= N || nm >= M) { ans = max(ans, d + 1); continue; }
			if (arr[nn][nm] == 'H') { ans = max(ans, d + 1); continue; }
			if (vst[nn][nm][i][a] >= d + 1) continue;
			if (d + 1 > N* M) { cout << -1; return 0; }
			vst[nn][nm][i][a] = d + 1;
			q.emplace(nn, nm, d + 1);
		}
	}
	cout << ans;
}