#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N;
pii ans[2][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int cur = 0;
	for (int i = 0; i < N; ++i)
	{
		int val[3];
		for (int k = 0; k < 3; ++k)
		{
			cin >> val[k];
			ans[cur ^ 1][k] = { INT_MIN,INT_MAX };
		}
		for (int j = 0; j < 3; ++j)
		{
			for (int k = -1; k < 2; ++k)
			{
				if (j + k < 0 || j + k>2) continue;
				ans[cur ^ 1][j+k].first = max(ans[cur ^ 1][j+k].first, ans[cur][j].first + val[j]);
				ans[cur ^ 1][j+k].second = min(ans[cur ^ 1][j+k].second, ans[cur][j].second + val[j]);
			}
		}
		cur ^= 1;
	}
	int mn = INT_MAX, mx = INT_MIN;
	for (int i = 0; i < 3; ++i)
	{
		mn = min(mn, ans[cur][i].second);
		mx = max(mx, ans[cur][i].first);
	}
	cout << mx << " " << mn;
}