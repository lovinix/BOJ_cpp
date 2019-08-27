#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, dif[3001], lo[3001], hi[3001], ans;
string arr[3001];
vector<pii> co;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dif, 0x3f, sizeof dif);
	memset(lo, -1, sizeof lo);
	memset(hi, 0x3f, sizeof hi);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		for (int j = 0; j < M; ++j)
		{
			if (arr[i][j] == 'X')
			{
				co.emplace_back(i, j);
				lo[j] = i;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == '#')
				if (hi[j] == 0x3f3f3f3f) hi[j] = i;
		}
	}
	for (int i = 0; i < M; ++i)
	{
		if (lo[i] == -1) continue;
		int n = lo[i], m = i;
		dif[i] = hi[i] - lo[i] - 1;
	}
	ans = 0x3f3f3f3f;
	for (int i = 0; i < M; ++i) ans = min(ans, dif[i]);
	for (auto& v : co) arr[v.first + ans][v.second] = 'X';
	for (int i = 0; i < N; ++i)
		cout << arr[i] << "\n";

}