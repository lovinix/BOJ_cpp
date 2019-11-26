#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[100'010], ans;
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i <= N; ++i)
	{
		while (!stk.empty() && arr[stk.top()] > arr[i])
		{
			int idx = stk.top();
			stk.pop();
			ans = max(ans, arr[idx] * (i - (stk.size() ? stk.top() + 1 : 0)));
		}
		stk.emplace(i);
	}
	cout << ans << "\n";

}