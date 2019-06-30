#include <bits/stdc++.h>
#include <bitset>

using namespace std;
int N, M, ans;
int ind[200001];
bool isvisited[200001];
bitset<200001> bset;
vector<vector<int>> arr, rev, scc;
stack<int> stk;

void dfs(int idx)
{
	isvisited[idx] = true;
	for (auto& next : arr[idx])
	{
		if (!isvisited[next])
			dfs(next);
	}
	stk.push(idx);
}

void dfs2(int idx)
{
	isvisited[idx] = true;
	bset.set(idx);
	scc[scc.size() - 1].push_back(idx);
	for (auto& next : rev[idx])
	{
		if (!isvisited[next])
			dfs2(next);
		else if (!bset[next])
			++ind[idx];
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		arr.push_back(vector<int>());
		rev.push_back(vector<int>());
	}
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		rev[v].push_back(u);
	}
	for (int i = 0; i < N; ++i)
	{
		if (!isvisited[i])
			dfs(i);
	}
	memset(isvisited, 0, sizeof(isvisited));
	while (!stk.empty())
	{
		int cur = stk.top();
		stk.pop();
		if (!isvisited[cur])
		{
			bset.reset();
			scc.push_back(vector<int>());
			dfs2(cur);
		}

	}
	for (auto& ar : scc)
	{
		bool flag = true;
		for (int cur : ar)
		{
			if (ind[cur] != 0)
			{
				flag = false;
				break;
			}
		}
		if(flag) ++ans;
	}
	cout << ans;
}
