#include <bits/stdc++.h>
using namespace std;
int N, M;
char arr[60][60];
queue<pair<int, int>> q[2];
bool isvisited[60][60];
int dn[] = { 1,-1,0,0 };
int dm[] = { 0,0,1,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		for (int j = 0; j < M; ++j)
		{
			switch (arr[i][j])
			{
			case '*' :
				q[0].push({ i,j });
				isvisited[i][j] = true;
				break;
			case 'S' :
				q[1].push({ i,j });
				isvisited[i][j] = true;
				break;
			}
		}
	}
	int t = 1;
	while (!q[1].empty())
	{
		int s[] = { q[0].size(),q[1].size() };
		for (int z = 0; z < 2; ++z)
		{
			for (int y = 0; y < s[z]; ++y)
			{
				int n = q[z].front().first;
				int m = q[z].front().second;
				q[z].pop();
				for (int i = 0; i < 4; ++i)
				{
					int nextn = n + dn[i];
					int nextm = m + dm[i];
					if (nextn < 0 || nextn >= N || nextm < 0 || nextm >= M)
						continue;
					if (arr[nextn][nextm] == 'X') continue;
					if (arr[nextn][nextm] == 'D')
					{
						if (z)
						{
							cout << t;
							return 0;
						}
						continue;
					}
					if (isvisited[nextn][nextm]) continue;
					isvisited[nextn][nextm] = true;
					q[z].push({ nextn,nextm });
				}
			}
		}
		++t;
	}
	cout << "KAKTUS";
}
