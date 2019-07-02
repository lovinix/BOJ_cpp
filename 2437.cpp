#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int cur = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > cur + 1)
		{
			cout << cur + 1;
			return 0;
		}
		cur += v[i];
	}
	cout << cur + 1;
}