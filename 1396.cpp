#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;
using pa = pair<int, int>;

int n, m, p[100001], Q, lo[100001], hi[100001], ans[100001][2];
vector<tu> e;
vector<pa> q;
vector<int> idx[1000001];

int find(int u);
void merge(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(p, -1, sizeof(p));
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		e.emplace_back(a-1, b-1, c);
	}
	sort(e.begin(), e.end(), [](tu& t1, tu& t2) {return get<2>(t1) < get<2>(t2); });
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int u, v;
		cin >> u >> v;
		q.emplace_back(u-1, v-1);
	}
	for (int i = 0; i < Q; ++i)
	{
		hi[i] = get<2>(e[e.size() - 1]);
	}
	while (1)
	{
		bool f = 0;
		for (int i = 0; i < Q; ++i)
		{
			if (lo[i] <= hi[i])
			{
				f = 1;
				idx[(lo[i] + hi[i]) / 2].emplace_back(i);
			}
		}
		if (!f) break;
		memset(p, -1, sizeof(p));
		for (int i = 0, mid = 0; i < m; ++mid)
		{
			int u, v, w;
			tie(u, v, w) = e[i];
			if (mid == w)
			{
				merge(u, v);
				++i;
			}
			for (auto& id : idx[mid])
			{
				if (find(q[id].first) == find(q[id].second))
				{
					hi[id] = mid - 1;
					ans[id][0] = mid;
					ans[id][1] = -p[find(q[id].first)];
				}
				else
					lo[id] = mid + 1;
			}
			idx[mid].clear();
		}
	}
	for (int i = 0; i < Q; ++i)
	{
		if (ans[i][0] == 0) cout << "-1\n";
		else cout << ans[i][0] << " " << ans[i][1] << "\n";
	}
}

int find(int u)
{
	return p[u] < 0 ? u : p[u] = find(p[u]);
}

void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v) return;
	p[u] += p[v];
	p[v] = u;
}