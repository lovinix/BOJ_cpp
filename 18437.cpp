#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, seg[4 * 100'010], lazy[4 * 100'010], ln[100'010], rn[100'010], num;
vector<int> adj[100'010];

void dfs(int u, int p)
{
	ln[u] = ++num;
	for (auto& v : adj[u])
	{
		if (v == p) continue;
		dfs(v, u);
	}
	rn[u] = num;
}

void pr(int n, int s, int e)
{
	if (lazy[n] == -1) return;
	seg[n] = (e - s + 1) * lazy[n];
	if (s == e) return;
	lazy[n * 2] = lazy[n];
	lazy[n * 2 + 1] = lazy[n];
	lazy[n] = -1;
}

void su(int l, int r, int v, int n = 1, int s = 1, int e = N)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] = v; pr(n, s, e); return; }
	int m = s + e >> 1;
	su(l, r, v, n * 2, s, m);
	su(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int qry(int l, int r, int n = 1, int s = 1, int e = N)
{
	pr(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return qry(l, r, n * 2, s, m) + qry(l, r, n * 2 + 1, m + 1, e);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int p; cin >> p;
		adj[p].emplace_back(i);
	}
	dfs(1, 0);
	su(1, N, 1);
	cin >> M;
	while (M--)
	{
		int f, i;
		cin >> f >> i;
		switch (f)
		{
		case 1:
		case 2:
			su(ln[i] + 1, rn[i], !(f - 1));
			break;
		case 3:
			cout << qry(ln[i] + 1, rn[i]) << "\n";
		}
	}
}