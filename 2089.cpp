#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli N;
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	if (N == 0) cout << 0;
	while (N)
	{
		int r = N % -2, q = N / -2;
		if (r < 0) r += 2, q += 1;
		ans.emplace_back(r);
		N = q;
	}
	for (auto it = ans.rbegin(); it != ans.rend(); ++it)
		cout << *it;
}