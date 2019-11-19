#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, K, v[200'010], cnt;
queue<pii> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	memset(v, 0x3f, sizeof v);
	q.emplace(N, 0);
	v[N] = 0;
	while (!q.empty())
	{
		auto [cur, d] = q.front();
		q.pop();
		if (cur == K) { ++cnt; continue; }
		if (cur * 2 <= 200'000 && v[cur * 2] >= d + 1) { q.emplace(cur * 2, d + 1); v[cur * 2] = d + 1; }
		if (cur + 1 <= K && v[cur + 1] >= d + 1) { q.emplace(cur + 1, d + 1); v[cur + 1] = d + 1; }
		if (cur - 1 >= 0 && v[cur - 1] >= d + 1) { q.emplace(cur - 1, d + 1); v[cur - 1] = d + 1; }
	}
	cout << v[K] << "\n" << cnt;
}