#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, J, K, dist[5010];
vector<pii> adj[5010];
set<int> AB[2];
auto cmp = [](pii& p1, pii& p2) {return p1.second > p2.second; };
priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> J >> K;
	for (int i = 0; i < K; ++i)
	{
		int A; cin >> A;
		AB[0].emplace(A);
	}
	for (int i = 0; i < K; ++i)
	{
		int B; cin >> B;
		AB[1].emplace(B);
	}
	for (int i = 0; i < M; ++i)
	{
		int X, Y, Z;
		cin >> X >> Y >> Z;
		adj[X].emplace_back(Y, Z);
		adj[Y].emplace_back(X, Z);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[J] = 0;
	pq.emplace(J, 0);
	while (!pq.empty())
	{
		auto [u, d] = pq.top();
		pq.pop();
		for (auto& [v, z] : adj[u])
		{
			if (dist[v] > d + z)
			{
				dist[v] = d + z;
				pq.emplace(v, d + z);
			}
		}
	}
	int mn = INT_MAX, idx = -1;
	for (int i = 1; i <= N; ++i)
	{
		if (i == J) continue;
		if (mn >= dist[i]) 
		{
			if (AB[0].count(i) == 0 && AB[1].count(i) == 0) continue;
			if (mn > dist[i]) { mn = dist[i]; idx = i; }
			else if (AB[0].count(i)) { mn = dist[i]; idx = i; } 
			else if (!AB[0].count(idx)) { mn = dist[i]; idx = i; }
		}
	}
	if (mn >= 0x3f3f3f3f) { cout << -1; return 0; }
	if (AB[0].count(idx)) { cout << "A\n" << mn; }
	else cout << "B\n" << mn;
}