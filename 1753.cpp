#include <bits/stdc++.h>
#define INF 123456789
using namespace std;
using pa = pair<int, int>;

int V, E, in[20001], d[20001];
vector<pa> adj[20001];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> V >> E;
	int st;
	cin >> st;
	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	q.push(st);
	in[st] = 1;
	fill(d, d + V + 1, INF);
	d[st] = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		in[cur]--;
		for (auto& next : adj[cur])
		{
			if (d[next.first] > d[cur] + next.second)
			{
				d[next.first] = d[cur] + next.second;
				if (!in[next.first])
				{
					q.push(next.first);
					in[next.first]++;
				}
			}
		}
	}
	for (int i = 1; i <= V; ++i)
	{
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}
}