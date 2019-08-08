#include <bits/stdc++.h>
#define MAX 123456789
using namespace std;
using pa = pair<int, int>;

int R, C, arr[501][501], ans[501][501], dn[] = {1,1,0,-1,-1,-1,0,1 }, dm[] = {0,-1,-1,-1,0,1,1,1 };
pa dp[501][501];

pa recv(int n, int m);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	for(int i=0;i<R;++i)
	{
		for(int j=0;j<C;++j)
		{
			cin >> arr[i][j];
			dp[i][j].first = -1;
			dp[i][j].second = -1;
		}
	}
	for(int i=0;i<R;++i)
	{
		for(int j=0;j<C;++j)
		{
			recv(i, j);
		}
	}
	for(int i=0;i<R;++i)
	{
		for(int j=0;j<C;++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

pa recv(int n, int m)
{
	if (dp[n][m].first != -1)
	{
		ans[dp[n][m].first][dp[n][m].second]++;
		return dp[n][m];
	}
	int mn = MAX, idx = -1;
	for (int i = 0; i < 8; ++i)
	{
		int nn = n + dn[i], nm = m + dm[i];
		if (nn < 0 || nm < 0 || nn >= R || nm >= C) continue;
		if (mn > arr[nn][nm])
		{
			mn = arr[nn][nm];
			idx = i;
		}
	}
	if (mn < arr[n][m]) { return dp[n][m] = recv(n + dn[idx], m + dm[idx]); }
	else { ans[n][m]++; return dp[n][m] =  { n,m }; }
}