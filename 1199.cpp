#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
int N;
vector<int> ans;

void dfs(int u);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int tmp = 0;
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
			tmp += arr[i][j];
		}
		if (tmp & 1)
		{
			cout << -1;
			return 0;
		}
	}
	dfs(0);
	for (int i = ans.size() - 1; i >= 0; --i)
	{
		cout << ans[i]+1 << " ";
	}

}

void dfs(int u)
{
	for (int v = 0; v < N; ++v)
	{
		if (arr[u][v])
		{
			--arr[u][v];
			--arr[v][u];
			dfs(v);
		}
	}
	ans.emplace_back(u);
}