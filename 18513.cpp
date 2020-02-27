#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

int N, K, dn[] = { -1,1 };
lli ans;
set<int> s;
queue<pii> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int v; cin >> v;
		q.emplace(v, 0);
		s.emplace(v);
	}
	int cur = 0;
	while (!q.empty())
	{
		auto [u, d] = q.front();
		q.pop();
		for (int i = 0; i < 2; ++i)
		{
			int v = u + dn[i];
			if (s.count(v)) continue;
			s.emplace(v);
			q.emplace(v, d + 1);
			ans += d + 1;
			if (++cur == K) goto end;
		}
	}
end:
	cout << ans;
}