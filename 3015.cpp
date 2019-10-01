#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

int N;
lli ans;
vector<pii> stk;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int v; cin >> v;
		int n = 1;
		while (!stk.empty() && stk.back().first <= v)
		{
			if (stk.back().first == v) n += stk.back().second;
			ans += stk.back().second;
			stk.pop_back();
		}
		if (!stk.empty()) ++ans;
		stk.emplace_back(v, n);
	}
	cout << ans;
}