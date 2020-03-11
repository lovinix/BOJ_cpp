#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tu = tuple<int, int, int>;

char buf[10'000'010];
int N, M, dist[1010], vst[1010], idx;
vector<pii> adj[1010];
priority_queue<tu, vector<tu>, greater<>> pq;

inline int nextInt()
{
	int ret = 0;
	while (buf[idx] != '\n' && buf[idx] != ' ' && buf[idx] != 0) ret = ret * 10 + buf[idx++] - '0';
	while (buf[idx] == '\n' || buf[idx] == ' ') ++idx;
	return ret;
}

int main()
{
	fread(buf, 1, sizeof buf, stdin);
	N = nextInt();
	M = nextInt();
	for (int i = 0; i < M; ++i)
	{
		int u = nextInt(), v = nextInt(), d = nextInt();
		adj[u].emplace_back(v, d);
		adj[v].emplace_back(u, d);
	}
	printf("%d\n", N - 1);
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(0, 0, 1);
	while (!pq.empty())
	{
		auto [d, p, u] = pq.top();
		pq.pop();
		if (vst[u]) continue;
		for (auto& [v, w] : adj[u])
		{
			if (dist[v] > d + w)
			{
				dist[v] = d + w;
				pq.emplace(dist[v], u, v);
			}
		}
		vst[u] = 1;
		if (p != 0)
			printf("%d %d\n", p, u);
	}
}