#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int bias = 1000, MAX = 2010;
int N, M, f[MAX][MAX], c[MAX][MAX], lv[MAX], w[MAX], src=0, dst = 2001;
vector<int> adj[MAX];
queue<int> q;

bool bfs();
int dfs(int u, int fl);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int cnt; cin >> cnt;
		while (cnt--)
		{
			int t; cin >> t;
			c[i][bias + t] = 1;
			adj[i].emplace_back(bias + t);
			adj[bias + t].emplace_back(i);
		}
		c[src][i] = 2;
		adj[src].emplace_back(i);
		adj[i].emplace_back(src);
	}
	for (int i = 1; i <= M; ++i)
	{
		c[bias + i][dst] = 1;
		adj[bias + i].emplace_back(dst);
		adj[dst].emplace_back(bias + i);
	}
	int ans = 0;
	while (bfs())
	{
		memset(w, 0, sizeof w);
		while (1)
		{
			int ret = dfs(src, 987654321);
			if (ret == 0) break;
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