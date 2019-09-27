#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 301, INF = 123456789;
int T, N, M, c[MAX][MAX], f[MAX][MAX], lv[MAX], w[MAX], src = 1, dst = N, dist[MAX][MAX];
vector<int> adj[MAX];
vector<pii> query;
queue<int> q;


bool bfs();
int dfs(int u, int fl);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> N >> M;
		dst = N;
		for (int i = 1; i <= N; ++i)
			adj[i].clear();
		query.clear();
		memset(c, 0, sizeof c);
		memset(f, 0, sizeof f);
		for (int i = 0; i < M; ++i)
		{
			int u, v, t;
			cin >> u >> v >> t;
			c[u][v] += t;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
			query.emplace_back(u, v);
		}
		while (bfs())
		{
			memset(w, 0, sizeof w);
			while (1)
			{
				int tmp = dfs(src, INF);
				if (!tmp) break;
			}
		}
		memset(dist, 0, sizeof dist);
		for (int i = 1; i <= N; ++i)
			for (auto& j : adj[i])
				if (c[i][j] - f[i][j] > 0) dist[i][j] = 1;
				else dist[i][j] = 0;
		for (int k = 1; k <= N; ++k)
			for (int i = 1; i <= N; ++i)
				for (int j = 1; j <= N; ++j)
					if (dist[i][k] && dist[k][j])
						dist[i][j] = 1;
		int ans = 0;
		for (auto& qu : query)
		{
			if (!dist[qu.first][qu.second]) ++ans;
		}
		cout << ans << "\n";
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