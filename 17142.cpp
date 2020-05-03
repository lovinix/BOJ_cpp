#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tu = tuple<int, int, int>;

int N, M, dr[] = { -1,1,0,0 }, dc[] = { 0,0,1,-1 }, A[51][51], bit, tot, vst[51][51], ans = 123456789;
vector<pii> co;
queue<tu> q;

void recv(int idx, int cnt)
{
	if (cnt == M)
	{
		memset(vst, 0, sizeof vst);
		for (int i = 0; i < co.size(); ++i)
		{
			if (bit >> i & 1)
			{
				q.emplace(co[i].first, co[i].second, 0);
				vst[co[i].first][co[i].second] = 1;
			}
		}
		int cur = 0, mx = 0;
		while (!q.empty())
		{
			auto [r, c, d] = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nr = r + dr[i], nc = c + dc[i];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				if (A[nr][nc] == 1) continue;
				if (vst[nr][nc]) continue;
				if (!A[nr][nc]) { ++cur; mx = max(mx, d + 1); }
				vst[nr][nc] = 1;
				q.emplace(nr, nc, d + 1);
			}
		}
		if (cur == tot) ans = min(ans, mx);
	}
	else if (idx == co.size()) return;
	else
	{
		bit |= 1 << idx;
		recv(idx + 1, cnt + 1);
		bit ^= 1 << idx;
		recv(idx + 1, cnt);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> A[i][j];
			tot += !A[i][j];
			if (A[i][j] == 2) co.emplace_back(i, j);
		}
	}
	recv(0, 0);
	cout << (ans == 123456789 ? -1 : ans);
}