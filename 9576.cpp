#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2020, bias = 1000;
int T, N, M, c[MAX][MAX], f[MAX][MAX], lv[MAX], w[MAX], src = 0, dst = 2001;
vector<int> adj[MAX];
queue<int> q;

bool bfs();
int dfs(int u, int fl);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		memset(c, 0, sizeof c);
		memset(f, 0, sizeof f);
		for (auto& v : adj) v.clear();
		cin >> N >> M;
		for (int i = 1; i <= M; ++i)
		{
			c[i + bias][dst] = 1;
			adj[i + bias].emplace_back(dst);
			adj[dst].emplace_back(i + bias);
			int a, b;
			cin >> a >> b;
			for (; a <= b; ++a)
			{
				adj[a].emplace_back(i + bias);
				adj[i + bias].emplace_back(a);
				c[a][i + bias] = 1;
			}
		}
		for (int i = 1; i <= N; ++i)
		{
			adj[src].emplace_back(i);
			adj[i].emplace_back(src);
			c[src][i] = 1;
		}
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