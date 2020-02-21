#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, A[1010];
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for_each(A, A + N, [](int& x) {cin >> x; });
	int cur = 1;
	for (int i = 0; i < N; ++i)
	{
		if (A[i] == cur) ++cur;
		else if (!stk.empty() && stk.top() == cur)
		{
			++cur;
			stk.pop();
			--i;
		}
		else
			stk.emplace(A[i]);
	}
	while (!stk.empty() && stk.top() == cur)
	{
		++cur; stk.pop();
	}
	if (cur == N + 1) cout << "Nice";
	else cout << "Sad";
}