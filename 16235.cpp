#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, K, arr[11][11], nu[11][11], dead[11][11], dn[] = { -1,-1,-1,0,1,1,1,0 }, dm[] = { -1,0,1,1,1,0,-1,-1 };
deque<int> tree[11][11];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			arr[i][j] = 5;
			cin >> nu[i][j];
		}
	}
	for (int i = 0; i < M; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].emplace_back(z);
	}
	while (K--)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				int len = tree[i][j].size();
				for (int k = 0; k < len; ++k)
				{
					int o = tree[i][j].front();
					tree[i][j].pop_front();
					if (arr[i][j] >= o) { arr[i][j] -= o; tree[i][j].emplace_back(++o); }
					else dead[i][j] += o / 2;
				}
			}
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				for (auto& o : tree[i][j])
				{
					if (o % 5 == 0)
					{
						for (int k = 0; k < 8; ++k)
						{
							int nn = i + dn[k], nm = j + dm[k];
							if (nn <= 0 || nn > N || nm <= 0 || nm > N) continue;
							tree[nn][nm].emplace_front(1);
						}
					}
				}
			}
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				arr[i][j] += nu[i][j];
				arr[i][j] += dead[i][j];
				dead[i][j] = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			ans += tree[i][j].size();
	cout << ans;
}