#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> ar;
int ans[1000000];
stack<pair<int, int>> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		ar.push_back({ i,tmp });
	}
	for (auto& v : ar)
	{
		while (!stk.empty() && stk.top().second < v.second)
		{
			ans[stk.top().first] = v.second;
			stk.pop();
		}
		stk.push(v);
	}
	while (!stk.empty())
	{
		ans[stk.top().first] = -1;
		stk.pop();
	}
	for (int i=0;i<n;++i)
	{
		cout << ans[i] << " ";
	}
}