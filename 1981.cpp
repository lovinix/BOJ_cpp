#include <bits/stdc++.h>
#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int N, ans=INT_MAX;
int arr[101][101];
bool isvisited[101][101];
queue<pair<int, int>> q;
int dn[] = { -1,1,0,0 }, dm[] = { 0,0,-1,1 };
int minv= INT_MAX, maxv;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
			minv = min(minv, arr[i][j]);
			maxv = max(maxv, arr[i][j]);
		}
	}
	int l = abs(arr[N - 1][N - 1] - arr[0][0]), r = maxv - minv;
	while(l <= r)
	{
		bool flag = false;
		int mid = (l + r) / 2;
		for (int lo = minv; lo <= maxv - mid; ++lo)
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					if (arr[i][j] >= lo && arr[i][j] <= lo + mid)
						isvisited[i][j] = false;
					else
						isvisited[i][j] = true;
				}
			}
			while (!q.empty()) q.pop();
			if(!isvisited[0][0]) q.emplace(0,0);
			while (!q.empty())
			{
				int n = q.front().first;
				int m = q.front().second;
				if (n == N - 1 && m == N - 1)
				{
					flag = true;
					break;
				}
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nextn = n + dn[i];
					int nextm = m + dm[i];
					if (nextn < 0 || nextn >= N || nextm < 0 || nextm >= N) continue;
					if (isvisited[nextn][nextm]) continue;
					isvisited[nextn][nextm] = true;
					q.emplace(nextn,nextm);
				}
			}
			if (flag)
				break;
		}
		if (flag)
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans;
}