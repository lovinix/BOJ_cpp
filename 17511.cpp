#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int INF = 123456789;
int N, M, arr[501][501];
pii query[500 * 500];
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (i == j) continue;
			else arr[i][j] = INF;
	for (int i = 0; i < M; ++i)
	{
		int u, v; cin >> u >> v;
		--u, --v;
		query[i] = { u,v };
		arr[u][v] = 1;
	}
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			auto& [a, b] = query[j];
			if (arr[i][a] == INF) goto next;
		}
		ans.emplace_back(i);
	next:;
	}
	cout << ans.size() << "\n";
	for (auto& i : ans)
		cout << i + 1 << " ";
}