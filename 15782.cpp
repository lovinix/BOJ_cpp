#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100'010;
int N, M, seg[4 * MAX], lazy[4 * MAX], num[MAX], visit[MAX], rn[MAX], cnt;
vector<int> adj[MAX];

void dfs(int u);
void pr(int n, int s, int e);
void su(int l, int r, int v, int n = 1, int s = 1, int e = N);
int sq(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i < N; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1);
	for (int i = 1; i <= N; ++i)
	{
		int v; cin >> v;
		su(num[i], num[i], v);
	}
	while (M--)
	{
		int f, x, y;
		cin >> f;
		switch (f)
		{
		case 1:
			cin >> x;
			cout << sq(num[x], rn[x]) << "\n";
			break;
		case 2:
			cin >> x >> y;
			su(num[x], rn[x], y);
		}
	}
}

void dfs(int u)
{
	visit[u] = 1;
	num[u] = ++cnt;
	for (auto& v : adj[u])
	{
		if (!visit[v]) dfs(v);
	}
	rn[u] = cnt;
}

void pr(int n, int s, int e)
{
	if (!lazy[n]) return;
	if ((e - s + 1) & 1) seg[n] ^= lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[n * 2] ^= lazy[n];
	lazy[n * 2 + 1] ^= lazy[n];
	lazy[n] = 0;
}

void su(int l, int r, int v, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] ^= v; pr(n, s, e); return; }
	int m = s + e >> 1;
	su(l, r, v, n * 2, s, m);
	su(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] ^ seg[n * 2 + 1];
}

int sq(int l, int r, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return sq(l, r, n * 2, s, m) ^ sq(l, r, n * 2 + 1, m + 1, e);
}