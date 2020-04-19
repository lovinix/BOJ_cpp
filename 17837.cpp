#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, K, A[20][20], D[20], dr[] = { 0,0,0,-1,1}, dc[] = { 0,1,-1,0,0 };
vector<int> B[20][20];
pii P[20];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
	for (int i = 1; i <= K; ++i)
	{
		auto& [r, c] = P[i];
		cin >> r >> c >> D[i];
		--r, --c;
		B[r][c].emplace_back(i);
	}
	for (int t = 1; t <= 1000; ++t)
	{
		for (int i = 1; i <= K; ++i)
		{
			auto [r, c] = P[i];
			int nr = r + dr[D[i]], nc = c + dc[D[i]];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || A[nr][nc] == 2)
			{
				D[i] & 1 ? ++D[i] : --D[i];
				nr = r + dr[D[i]], nc = c + dc[D[i]];
				if(nr < 0 || nc < 0 || nr >= N || nc >= N || A[nr][nc] == 2)
					continue;
			}
			auto pos = find(B[r][c].begin(), B[r][c].end(), i);
			for (auto it = A[nr][nc] ? --B[r][c].end() : pos; it != B[r][c].end(); A[nr][nc] ? --it : ++it)
			{
				B[nr][nc].emplace_back(*it);
				if (A[nr][nc] && it == pos) break;
			}
			for (auto it = pos; it != B[r][c].end(); ++it)
				P[*it] = { nr,nc };
			B[r][c].erase(pos, B[r][c].end());
			if (B[nr][nc].size() > 3) { cout << t; return 0; }
		}
	}
	cout << -1;
}