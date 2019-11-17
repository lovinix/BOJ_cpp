#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using lli = long long;

int N;
lli ans;
stack<pii> stk;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--)
	{
		int f; cin >> f;
		if (f == 0)
		{
			if (stk.empty()) continue;
			if (--stk.top().second == 0)
			{
				ans += stk.top().first;
				stk.pop();
			}
		}
		else
		{
			int A, T;
			cin >> A >> T;
			if (T == 1) ans += A;
			else stk.emplace(A, --T);
		}
	}
	cout << ans;
}