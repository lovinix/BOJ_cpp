#include <bits/stdc++.h>
#define INF 123456789
using namespace std;


int N, M, dist[20001];
vector<int> adj[20001];
queue<int> q;

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
		adj[v].emplace_back(u);
	}
	q.push(1);
	fill(dist, dist + N + 1, INF);
	dist[1] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int& next : adj[cur])
		{
			if (dist[next] > dist[cur] + 1)
			{
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
	int a = -1, b = -1, c = -1;
	for (int i = 1; i <= N; ++i)
	{
		if (b < dist[i])
		{
			a = i;
			b = dist[i];
			c = 1;
		}
		else if (b == dist[i])
		{
			++c;
		}
	}
	cout << a << " " << b << " " << c;
}