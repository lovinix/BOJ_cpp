#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, K, A, B, ans[1010], cnt[1010], in[1010];
vector<int> adj[1010];
set<int> s;
queue<pii> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		in[v]++;
	}
	cin >> A >> B >> K;
	for (int i = 0; i < K; ++i)
	{
		int c; cin >> c;
		s.emplace(c);
	}
	s.emplace(A); s.emplace(B);
	for (int i = 1; i <= N; ++i)
		if (in[i] == 0) q.emplace(i, i == A ? 1 : 0);
	ans[A] = 1;
	while (!q.empty())
	{
		auto [u, c] = q.front();
		if (u == B && c == s.size()) { cout << ans[B]; return 0; }
		q.pop();
		for (auto& v : adj[u])
		{
			if (cnt[v] == c) { ans[v] += ans[u]; }
			else if (cnt[v] < c)
			{
				ans[v] = ans[u];
				cnt[v] = c;
			}
			if (--in[v] == 0)
				q.emplace(v, cnt[v] + (s.count(v) ? 1 : 0));
		}
	}
	cout << 0;
}