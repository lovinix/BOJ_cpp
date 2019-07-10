#include <bits/stdc++.h>
using namespace std;

int N, M, sum;
int arr[101][101], dn[] = { 1,-1,0,0 }, dm[] = { 0,0,1,-1 };
bool isvisited[101][101];
queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}
	if (!sum) { cout << "0\n0"; return 0; }
	int time = 0;
	while (sum)
	{
		q.push({ 0,0 });
		for (auto& t : isvisited)
			memset(t, 0, sizeof(t));
		int dif = 0;
		while (!q.empty())
		{
			int s = q.size();
			for (int z = 0; z < s; ++z)
			{
				int n = q.front().first;
				int m = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nextn = n + dn[i];
					int nextm = m + dm[i];
					if (nextn < 0 || nextn >= N || nextm < 0 || nextm >= M) continue;
					if (isvisited[nextn][nextm]) continue;
					isvisited[nextn][nextm] = true;
					if (arr[nextn][nextm] == 0) q.push({ nextn,nextm });
					else
					{
						arr[nextn][nextm] = 0;
						++dif;
					}
				}
			}
		}
		++time;
		if (sum == dif)
		{
			cout << time << "\n" << dif;
			return 0;
		}
		sum -= dif;
	}
}