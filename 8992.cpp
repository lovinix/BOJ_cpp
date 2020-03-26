#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tu = tuple<int, int, int, int, int>;

struct Edge
{
	int v, p, cp, co;
	Edge(int _v, int _p, int _cp, int _co) : v(_v), p(_p), cp(_cp), co(_co) {}
};

constexpr int sz = 410, src = 0, snk = 405, INF = 0x3f3f3f3f;
int T, N, M, inq[sz], dist[sz];
tu A[210], B[210];
pii prv[sz];
vector<Edge> adj[sz];
queue<int> q;

bool spfa()
{
	memset(inq, 0, sizeof inq);
	memset(dist, 0x3f, sizeof dist);
	q.push(src);
	dist[src] = 0;
	inq[src] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for (int i = 0; i < adj[u].size(); ++i)
		{
			auto& e = adj[u][i];
			if (e.cp <= 0) continue;
			if (dist[e.v] > dist[u] + e.co)
			{
				dist[e.v] = dist[u] + e.co;
				prv[e.v].first = u; prv[e.v].second = i;
				if (!inq[e.v]) { q.push(e.v); inq[e.v] = 1; }
			}
		}
	}
	return dist[snk] != 0x3f3f3f3f;
}

pii mcmf()
{
	int fl = 0, co = 0;
	while (spfa())
	{
		int c = 0, f = INF;
		for (int i = snk; i != src; i = prv[i].first)
		{
			auto& e = adj[prv[i].first][prv[i].second];
			f = min(f, e.cp);
			c += e.co;
		}
		fl += f; co += f * c;
		for (int i = snk; i != src; i = prv[i].first)
		{
			auto& e = adj[prv[i].first][prv[i].second];
			e.cp -= f;
			adj[e.v][e.p].cp += f;
		}
	}
	return { fl,co };
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		for (auto& vt : adj) vt.clear();
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
		{
			auto& [X1, Y1, X2, Y2, W] = A[i];
			cin >> X1 >> Y1 >> X2 >> Y2 >> W;
			if (X1 > X2) swap(X1, X2);
			adj[src].emplace_back(i, adj[i].size(), 1, 0);
			adj[i].emplace_back(src, adj[src].size() - 1, 0, 0);
		}
		for (int i = 1; i <= M; ++i)
		{
			auto& [X1, Y1, X2, Y2, W] = B[i];
			cin >> X1 >> Y1 >> X2 >> Y2 >> W;
			if (Y1 > Y2) swap(Y1, Y2);
			adj[i + N].emplace_back(snk, adj[snk].size(), 1, 0);
			adj[snk].emplace_back(i + N, adj[i + N].size() - 1, 0, 0);
		}
		for (int i = 1; i <= N; ++i)
		{
			auto& [X1, Y1, X2, Y2, W1] = A[i];
			for (int j = 1; j <= M; ++j)
			{
				auto& [X3, Y3, X4, Y4, W2] = B[j];
				if (X1 <= X3 && X3 <= X2 && Y3 <= Y1 && Y1 <= Y4)
				{
					adj[i].emplace_back(j + N, adj[j + N].size(), 1, -W1 * W2);
					adj[j + N].emplace_back(i, adj[i].size() - 1, 0, W1 * W2);
				}
			}
		}
		auto [f, c] = mcmf();
		cout << f << " " << -c << "\n";
	}
}