#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int>;

int N, M, v[110][110][2], dn[] = { -1,1,0,0 }, dm[] = { 0,0,-1,1 };
lli arr[110][110];
queue<tu> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	lli l = arr[0][0], r = 1e9, ans;
	while (l <= r)
	{
		lli mid = l + r >> 1;
		while (!q.empty()) q.pop();
		memset(v, 0, sizeof v);
		q.emplace(0, 0, 0);
		v[0][0][0] = 1;
		while (!q.empty())
		{
			auto [n, m, f] = q.front();
			q.pop();
			for (int j = 0; j < 2; ++j)
			{
				if (j && f) break;
				for (int i = 0; i < 4; ++i)
				{
					int nn = n + (j + 1) * dn[i], nm = m + (j + 1) * dm[i];
					int nf = f || j;
					if (nn < 0 || nn >= N || nm < 0 || nm >= M) continue;
					if (v[nn][nm][nf]) continue;
					if (arr[nn][nm] > mid) continue;
					v[nn][nm][nf] = 1;
					q.emplace(nn, nm, nf);
				}
			}
		}
		for (int i = 0; i < 2; ++i)
			if (v[N - 1][M - 1][i]) goto next;
		l = mid + 1;
		continue;
	next:
		ans = mid;
		r = mid - 1;
	}
	cout << ans;
}