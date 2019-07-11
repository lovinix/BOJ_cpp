#include <bits/stdc++.h>
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;

int N, M;
vector<int> arr[10001];
int d[10001], fin[10001];
int cnt = 0;
stack<int> stk;
vector<vector<int>> ans;

int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (d[i] == 0) dfs(i);
	}
	for (auto& v : ans)
	{
		sort(v.begin(), v.end());
	}
	sort(ans.begin(), ans.end(), [](auto &u, auto &v){return u[0] < v[0]; });
	cout << ans.size() << "\n";
	for (auto& v : ans)
	{
		for (auto& i : v)
		{
			cout << i << " ";
		}
		cout << "-1\n";
	}
}

int dfs(int u)
{
	d[u] = ++cnt;
	stk.push(u);
	int ret = d[u];
	for (auto& v : arr[u])
	{
		if (d[v] == 0)
		{
			int t = dfs(v);
			ret = min(ret, t);
		}
		else if (!fin[v])
			ret = min(ret, d[v]);
	}
	if (ret == d[u])
	{
		vector<int> scc;
		while (true)
		{
			int cur = stk.top();
			stk.pop();
			scc.push_back(cur);
			fin[cur] = true;
			if (cur == u) break;
		}
		ans.push_back(scc);
	}
	return ret;
}