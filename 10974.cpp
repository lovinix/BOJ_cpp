#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 1; i <= N; ++i)
		v.push_back(i);
	do
	{
		for (int i : v)
		{
			cout << i << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
}