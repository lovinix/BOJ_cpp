#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tu = tuple<int, int, int>;

int N, S, E, visit[100'001];
vector<pii> adj[100'001];
queue<tu> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> S >> E;
	for (int i = 1; i < N; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	q.push({ S,0,0 });
	while (!q.empty())
	{
		auto [cur, d, mx] = q.front();
		q.pop();
		if (cur == E) { cout << d-mx; return 0; }
		for (auto& v : adj[cur])
		{
			if (visit[v.first]) continue;
			visit[v.first] = 1;
			q.push({ v.first,d + v.second,max(mx,v.second) });
		}
	}
}