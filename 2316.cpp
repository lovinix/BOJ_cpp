#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 801, bias = 400;
int N, P, c[MAX][MAX], f[MAX][MAX], lv[MAX], w[MAX], src = 1, dst = 2;
vector<int> adj[MAX];
queue<int> q;

bool bfs();
int dfs(int u, int fl);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> P;
	for (int i = 1; i <= N; ++i)
	{
		adj[i].emplace_back(i + bias);
		adj[i + bias].emplace_back(i);
		c[i][i + bias] = 1;
	}
	for (int i = 0; i < P; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u + bias].emplace_back(v);
		adj[v].emplace_back(u + bias);
		adj[v + bias].emplace_back(u);
		adj[u].emplace_back(v + bias);
		c[u + bias][v] = 1;
		c[v + bias][u] = 1;
	}
	c[src][src + bias] = 987654321;
	int ans = 0;
	while (bfs())
	{
		memset(w, 0, sizeof w);
		while (1)
		{
			int ret = dfs(src, 987654321);
			if (!ret) break;
			ans += ret;
		}
	}
	cout << ans;

}

bool bfs()
{
	memset(lv, -1, sizeof lv);
	q.emplace(src);
	lv[src] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto& v : adj[u])
		{
			if (lv[v] == -1 && c[u][v] - f[u][v] > 0)
				q.push(v), lv[v] = lv[u] + 1;
		}
	}
	return lv[dst] != -1;
}

int dfs(int u, int fl)
{
	if (u == dst) return fl;
	for (int& i = w[u]; i < adj[u].size(); ++i)
	{
		int v = adj[u][i];
		if (lv[v] == lv[u] + 1 && c[u][v] - f[u][v] > 0)
		{
			int ret = dfs(v, min(fl, c[u][v] - f[u][v]));
			if (ret)
			{
				f[u][v] += ret;
				f[v][u] -= ret;
				return ret;
			}
		}
	}
	return 0;
}