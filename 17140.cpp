#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int A[110][110], R, C, K, cnt[110];
vector<int> vt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> R >> C >> K;
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j)
			cin >> A[i][j];
	int ans = 0, rn = 3, cn = 3;
	while (ans <= 100)
	{
		if (A[R][C] == K) { cout << ans; return 0; }
		++ans;
		int nsz = -1;
		for (int i = 1; i <= max(rn, cn); ++i)
		{
			vt.clear();
			memset(cnt, 0, sizeof cnt);
			for (int j = 1; j <= max(rn, cn); ++j)
			{
				auto cur = rn >= cn ? A[i][j] : A[j][i];
				if (cur == 0) continue;
				cnt[cur]++;
				vt.emplace_back(cur);
			}
			sort(vt.begin(), vt.end());
			vt.erase(unique(vt.begin(), vt.end()), vt.end());
			sort(vt.begin(), vt.end(), [&](int& a, int& b) {return cnt[a] == cnt[b] ? a < b : cnt[a] < cnt[b]; });
			for (int k = 1; k <= min((int)vt.size() * 2, 100); k += 2)
			{
				(rn >= cn ? A[i][k] : A[k][i]) = vt[k / 2];
				(rn >= cn ? A[i][k + 1] : A[k + 1][i]) = cnt[vt[k / 2]];
			}
			for (int k = min((int)vt.size() * 2, 100) + 1; k <= 100; ++k)
				(rn >= cn ? A[i][k] : A[k][i]) = 0;
			nsz = max(nsz, min((int)vt.size() * 2, 100));
		}
		(rn >= cn ? cn : rn) = nsz;
	}
	cout << -1;
}