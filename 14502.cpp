#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, v[10][10], arr[10][10], dn[] = { -1,1,0,0 }, dm[] = { 0,0,-1,1 }, tz, ans;
unsigned long long mask;
queue<pii> q;
vector<pii> vi, sp;

void recv(int idx, int cnt);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for(int i=0;i<N;++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2) vi.emplace_back(i, j);
			if (!arr[i][j]) sp.emplace_back(i, j), tz++;
		}
	recv(0, 0);
	cout << ans;
}

void recv(int idx, int cnt)
{
	if (cnt > 3) return;
	if (idx == sp.size() && cnt < 3) return;
	if (cnt == 3)
	{
		for (int i = 0; i < sp.size(); ++i)
		{
			auto& [n, m] = sp[i];
			if (mask & 1LL << i) arr[n][m] = 1;
		}
		memset(v, 0, sizeof v);
		for (auto& [r, c] : vi) q.emplace(r, c), v[r][c] = 1;
		int cnt = 0;
		while (!q.empty())
		{
			auto [n, m] = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nn = n + dn[i], nm = m + dm[i];
				if (nn < 0 || nm < 0 || nn >= N || nm >= M) continue;
				if (v[nn][nm]) continue;
				if (arr[nn][nm] != 0) continue;
				v[nn][nm] = 1;
				q.emplace(nn, nm);
				++cnt;
			}
		}
		ans = max(ans, tz - cnt - 3);
		for (int i = 0; i < sp.size(); ++i)
		{
			auto& [n, m] = sp[i];
			if (mask & 1LL << i) arr[n][m] = 0;
		}
	}
	else
	{
		mask |= 1LL << idx;
		recv(idx + 1, cnt + 1);
		mask ^= 1LL << idx;
		recv(idx + 1, cnt);
	}
}