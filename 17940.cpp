#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;
using pii = pair<int, int>;

int N, M, C[1010], E[1010][1010], vst[1010];
pii dist[1010];
auto cmp = [](tu& t1, tu& t2) {return get<1>(t1) == get<1>(t2) ? get<2>(t1) > get<2>(t2) : get<1>(t1) > get<1>(t2); };
priority_queue<tu, vector<tu>, decltype(cmp)> pq(cmp);

bool operator>(const pii& p1, const pii& p2) { return p1.first == p2.first ? p1.second > p2.second:p1.first > p2.first; };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) dist[i] = { 1e9,1e9 };
	for (int i = 0; i < N; ++i)
		cin >> C[i];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> E[i][j];
	pq.emplace(0, 0, 0);
	dist[0] = { 0,0 }, vst[0] = 1;
	while (!pq.empty())
	{
		auto [u, t, d] = pq.top();
		pq.pop();
		for (int v = 0; v < N; ++v)
		{
			if (E[u][v] == 0) continue;
			int nt = t + (C[u] ^ C[v]);
			int nd = d + E[u][v];
			pii ndst = { nt,nd };
			if (dist[v] > ndst)
			{
				dist[v] = ndst;
				pq.emplace(v, nt, nd);
			}
		}
	}
	cout << dist[M].first << " " << dist[M].second;
}