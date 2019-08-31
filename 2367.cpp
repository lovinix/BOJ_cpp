#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int bias = 200, MAX = 350, src = 0, dst = 301;
int N, D, K;
int c[MAX][MAX], f[MAX][MAX], lv[MAX], w[MAX];
vector<int> adj[MAX];
queue<int> q;

bool bfs();
int dfs(int u, int fl);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K >> D;
	for (int i = 1; i <= N; ++i)
	{
		c[src][i] = K;
		adj[src].emplace_back(i);
		adj[i].emplace_back(src);
	}
	for (int i = 1; i <= D; ++i)
	{
		int t; cin >> t;
		c[bias + i][dst] = t;
		adj[bias + i].emplace_back(dst);
		adj[dst].emplace_back(bias + i);
	}
	for (int i = 1; i <= N; ++i)
	{
		int n; cin >> n;
		while (n--)
		{
			int t; cin >> t;
			adj[i].emplace_back(bias + t);
			adj[bias + t].emplace_back(i);
			c[i][bias + t] = 1;
		}
	}
	int ans = 0;
	while (bfs())
	{
		fill(w, w + MAX, 0);
		while (1)
		{
			int fl = dfs(src, 987654321);
			if (fl == 0) break;
			ans += fl;
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
				q.emplace(v), lv[v] = lv[u] + 1;
		}
	}
	return lv[dst] != -1;
}

int dfs(int u, int fl)
{
	if (u == dst) return fl;
	for (int& i = w[u]; i<adj[u].size();++i)
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