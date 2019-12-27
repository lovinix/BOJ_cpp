#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, C, Q, lb[200'010], rb[200'010], seg[4 * 200'010], d[200'010], cnt;
vector<int> adj[200'010];

void dfs(int u, int p);
void u(int i, int n = 1, int s = 1, int e = N);
int q(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> C;
	for (int i = 1; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	dfs(C, 0);
	cin >> Q;
	while (Q--)
	{
		int f, a;
		cin >> f >> a;
		if (f == 1)
			u(lb[a]);
		else
		{
			cout << 1LL * d[a] * q(lb[a], rb[a]) << '\n';
		}
	}
}

void dfs(int u, int p)
{
	lb[u] = ++cnt;
	d[u] = d[p] + 1;
	for (auto& v : adj[u])
	{
		if (v == p)
			continue;
		dfs(v, u);
	}
	rb[u] = cnt;
}

void u(int i, int n, int s, int e)
{
	if (s > i || e < i)
		return;
	seg[n]++;
	if (s == e)
		return;
	int m = s + e >> 1;
	u(i, n * 2, s, m);
	u(i, n * 2 + 1, m + 1, e);
}

int q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l)
		return 0;
	if (l <= s && e <= r)
		return seg[n];
	int m = s + e >> 1;
	return q(l, r, n * 2, s, m) + q(l, r, n * 2 + 1, m + 1, e);
}