#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, L, R, A[51][51], vst[51][51], dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 }, sum, cnt, ans;

int recv(int r, int c, int t)
{
	int ret = 0;
	vst[r][c] = t + 1;
	if (t == 0) { sum += A[r][c]; cnt++; }
	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i], nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
		if (vst[nr][nc] != t) continue;
		if (int dif = abs(A[r][c] - A[nr][nc]); dif<L || dif>R) continue;
		recv(nr, nc, t);
		ret = 1;
	}
	if (t == 1) A[r][c] = sum / cnt;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
	while (true)
	{
		int fl = 0;
		memset(vst, 0, sizeof vst);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (vst[i][j]) continue;
				sum = cnt = 0;
				int t = recv(i, j, 0);
				if (t) { fl = 1; recv(i, j, 1); }
			}
		}
		if (!fl) break;
		else ++ans;
	}
	cout << ans;
}