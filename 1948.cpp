#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

char buf[10'000'010];
int N, M, mx[2][10'010], ind[2][10'010], st, ed, ans, idx;
vector<pii> adj[2][10'010];
queue<int> q;

inline int nextInt()
{
	int ret = 0;
	while (buf[idx] != '\n' && buf[idx] != ' ' && buf[idx] != 0) ret = ret * 10 + buf[idx++] - '0';
	while (buf[idx] == '\n' || buf[idx] == ' ') ++idx;
	return ret;
}

void Tsort(int f)
{
	auto& ad = adj[f];
	auto& m = mx[f];
	auto& in = ind[f];
	q.emplace(f ? ed : st);
	while (!q.empty())
	{
		auto u = q.front();
		q.pop();
		for (auto& [v, w] : ad[u])
		{
			m[v] = max(m[v], m[u] + w);
			if (f == 0 && (m[u] + w + mx[1][v] == mx[1][st])) ++ans;
			if (!--in[v]) q.emplace(v);
		}
	}
}

int main()
{
	fread(buf, 1, sizeof buf, stdin);
	N = nextInt();
	M = nextInt();
	for (int i = 0; i < M; ++i)
	{
		int u = nextInt(), v = nextInt(), w = nextInt();
		adj[0][u].emplace_back(v, w);
		adj[1][v].emplace_back(u, w);
		ind[0][v]++;
		ind[1][u]++;
	}
	st = nextInt();
	ed = nextInt();
	Tsort(1);
	Tsort(0);
	printf("%d\n%d", mx[1][st], ans);
}