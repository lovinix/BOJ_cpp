#include <bits/stdc++.h>
using namespace std;

int N, arr[11][11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; ++i)
	{
		v.push_back(i);
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}
	int ans = INT_MAX;
	do
	{
		int cur = 0;
		bool flag = false;
		for (int i = 0; i < N-1; ++i)
		{
			if(arr[v[i]][v[i+1]])
				cur += arr[v[i]][v[i + 1]];
			else
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			if (arr[v[N - 1]][v[0]])
				cur += arr[v[N - 1]][v[0]];
			else
				flag = true;
		}
		if(!flag) 
			ans = min(cur, ans);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;

}