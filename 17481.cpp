#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2010, bias = 1000, INF = 123456789;
int N, M, lv[MAX], w[MAX], c[MAX][MAX], f[MAX][MAX], src = 0, dst = MAX - 1;
string arr[MAX];
vector<int> adj[MAX];
queue<int> q;

bool bfs();
int dfs(int u, int fl);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; ++i)
	{
		cin >> arr[i];
		adj[i + bias].emplace_back(dst);
		adj[dst].emplace_back(i + bias);
		c[i + bias][dst] = 1;
	}
	sort(arr + 1, arr + M + 1);
	for (int i = 1; i <= N; ++i)
	{
		int cnt; cin >> cnt;
		while (cnt--)
		{
			string s; cin >> s;
			int idx = lower_bound(arr + 1, arr + M + 1, s) - arr;
			adj[i].emplace_back(idx + bias);
			adj[idx + bias].emplace_back(i);
			c[i][idx + bias] = 1;
		}
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
			int ret = dfs(src, INF);
			if (!ret) break;
			ans += ret;
		}
	}
	if (ans == N) cout << "YES";
	else cout << "NO\n" << ans;
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