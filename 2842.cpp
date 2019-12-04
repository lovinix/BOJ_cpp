#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, h[51][51], vst[51][51], dn[] = { -1,-1,-1,0,1,1,1,0 }, dm[] = { -1,0,1,1,1,0,-1,-1}, tot;
int sr, sc, mx;
string arr[51];
set<int> s;
queue<pii> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		for (int j = 0; j < N; ++j)
		{
			if (arr[i][j] == 'K') ++tot;
			if (arr[i][j] == 'P') { sr = i; sc = j; }
		}
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			cin >> h[i][j];
			mx = max(mx, h[i][j]);
			s.emplace(h[i][j]);
		}
	int l = 0, r = mx, ans = 0;
	while (l <= r)
	{
		int mid = l + r >> 1;
		for (int st = max(0, h[sr][sc] - mid); st <= min(h[sr][sc],mx); ++st)
		{
			if (!s.count(st)) continue;
			memset(vst, 0, sizeof vst);
			int cnt = 0;
			q.emplace(sr, sc);
			while (!q.empty())
			{
				auto [n, m] = q.front();
				q.pop();
				for (int i = 0; i < 8; ++i)
				{
					int nn = n + dn[i], nm = m + dm[i];
					if (nn < 0 || nn >= N || nm < 0 || nm >= N) continue;
					if (vst[nn][nm]) continue;
					if (h[nn][nm] > st + mid || h[nn][nm]<st) continue;
					vst[nn][nm] = 1;
					if (arr[nn][nm] == 'K') ++cnt;
					q.emplace(nn, nm);
				}
			}
			if (cnt == tot) { ans = mid; r = mid - 1; goto next; }
		}
		l = mid + 1;
	next:;
	}
	cout << ans;
}