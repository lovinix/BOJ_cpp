#include <bits/stdc++.h>
using namespace std;
using t = tuple<int, int, int>;

auto cmp = [&](t v1, t v2) {return get<2>(v1) > get<2>(v2); };
priority_queue<t, vector<t>, decltype(cmp)> pq(cmp);
int N, M, sum, p[200001];
int find(int u);
void merge(int u, int v, int z);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> M >> N)
	{
		if (M == 0 && N == 0) return 0;
		sum = 0;
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < N; ++i)
		{
			int x, y, z;
			cin >> x >> y >> z;
			sum += z;
			pq.push({ x,y,z });
		}
		for (int i = 0; i < M; ++i)
		{
			p[i] = i;
		}
		while (M-1)
		{
			auto [x,y,z] = pq.top();
			pq.pop();
			merge(x,y,z);
		}
		cout << sum << "\n";
	}
}

int find(int u)
{
	if (u == p[u]) return u;
	return p[u] = find(p[u]);
}

void merge(int u, int v, int z)
{
	u = find(u); v = find(v);
	if (u == v) return;
	p[v] = u;
	--M;
	sum -= z;
}