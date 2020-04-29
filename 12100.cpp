#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 }, A[21][21], B[21][21], vst[21][21], st[5];

int recv(int idx)
{
	if (idx != 5) 
	{
		int ret = -1;
		for (int i = 0; i < 4; ++i)
		{
			st[idx] = i;
			ret = max(ret, recv(idx + 1));
		}
		return ret;
	}
	else
	{
		memcpy(B, A, sizeof A);
		for (int i = 0; i < 5; ++i)
		{
			memset(vst, 0, sizeof vst);
			for (int r = (st[i] & 1 ? N - 1 : 0); (st[i] & 1 ? r >= 0 : r < N); (st[i] & 1 ? --r : ++r))
			{
				for (int c = (st[i] & 1 ? N - 1 : 0); (st[i] & 1 ? c >= 0 : c < N); (st[i] & 1 ? --c : ++c))
				{
					if (B[r][c] == 0) continue;
					int nr = r + dr[st[i]], nc = c + dc[st[i]];
					while (nr >= 0 && nc >= 0 && nr < N && nc < N && !vst[nr][nc] && B[nr][nc] == 0)
						nr += dr[st[i]], nc += dc[st[i]];
					if (r == nr && c == nc) continue;
					if (nr >= 0 && nc >= 0 && nr < N && nc < N && !vst[nr][nc] && B[nr][nc] == B[r][c])
					{
						vst[nr][nc] = 1;
						B[nr][nc] *= 2;
						B[r][c] = 0;
						continue;
					}
					nr -= dr[st[i]], nc -= dc[st[i]];
					swap(B[r][c], B[nr][nc]);
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				ans = max(ans, B[i][j]);
		return ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
	cout << recv(0);
}