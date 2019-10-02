#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli A, B;
set<lli> v;
queue<lli> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> A >> B;
	q.emplace(A);
	int cnt = 1;
	while (!q.empty())
	{
		int sz = q.size();
		for (int z = 0; z < sz; ++z)
		{
			lli cur = q.front();
			q.pop();
			if (cur == B) { cout << cnt; return 0; }
			lli tmp = cur * 2;
			if (tmp > B) continue;
			q.emplace(tmp);
			tmp = cur * 10 + 1;
			if (tmp > B) continue;
			q.emplace(tmp);
		}
		++cnt;
	}
	cout << -1;
}