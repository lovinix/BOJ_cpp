#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
set<int> s[510];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j) continue;
			s[i].emplace(j);
		}
	}
	int cur = 1, sz = N * (N - 1) / 2;
	s[1].erase(N); s[N].erase(1);
	cout << "a1 ";
	while (sz-- && s[cur].size())
	{
		int nxt = *s[cur].begin();
		cout << "a" << nxt << " ";
		s[cur].erase(nxt);
		s[nxt].erase(cur);
		cur = nxt;
	}
	cout << "a1";
}