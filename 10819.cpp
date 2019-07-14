#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int ans = -1;
	do
	{
		int cur = 0;
		for (int i = 0; i < v.size() - 1; ++i)
		{
			cur += abs(v[i + 1] - v[i]);
		}
		ans = max(ans, cur);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
}