#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Sh
{
	int a, b, c;
	Sh() : a(0), b(0), c(0) {}
	Sh(int _a, int _b, int _c) :a(_a), b(_b), c(_c) {}
	bool operator<(Sh& s) { return a <= s.a && b <= s.b && c <= s.c; }
	bool operator==(Sh& s) { return a == s.a && b == s.b && c == s.c; }
};

const int MAX = 110, bias = 50;
int N, c[MAX][MAX], f[MAX][MAX], lv[MAX], w[MAX], src = 0, dst = 101;
vector<int> adj[MAX];
queue<int> q;
Sh arr[MAX];

bool bfs();
int dfs(int u, int fl);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int a, b, d; cin >> a >> b >> d;
		arr[i] = Sh(a, b, d);
		c[src][i] = 2;
		adj[src].emplace_back(i);
		adj[i].emplace_back(src);
		adj[i + bias].emplace_back(dst);
		adj[dst].emplace_back(i + bias);
		c[i + bias][dst] = 1;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j) continue;
			if (arr[i] < arr[j])
			{
				if (arr[i] == arr[j])
				{
					if (i < j)
					{
						adj[j].emplace_back(i + bias);
						adj[i + bias].emplace_back(j);
						c[j][i + bias] = 1;
					}
				}
				else
				{
					adj[j].emplace_back(i + bias);
					adj[i + bias].emplace_back(j);
					c[j][i + bias] = 1;
				}
			}
		}
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
	cout << N-ans;

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