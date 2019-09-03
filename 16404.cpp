#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MAX = 100'010;
int N, M, num[MAX], rn[MAX], node_num;
lli seg[4 * MAX], lazy[4 * MAX];
vector<int> adj[MAX];

void dfs(int u);
void pr(int n, int s, int e);
void su(int l, int r, int v, int n = 1, int s = 1, int e = N);
lli sq(int i, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int t; cin >> t;
		if (i == 1) continue;
		adj[t].emplace_back(i);
	}
	dfs(1);
	while (M--)
	{
		int f, i, w;
		cin >> f;
		if (f == 1)
		{
			cin >> i >> w;
			su(num[i], rn[i], w);
		}
		else
		{
			cin >> i;
			cout << sq(num[i]) << "\n";
		}
	}
}

void dfs(int u)
{
	num[u] = ++node_num;
	for (auto& v : adj[u])
		dfs(v);
	rn[u] = node_num;
}

void pr(int n, int s, int e)
{
	if (!lazy[n]) return;
	seg[n] += (e - s + 1) * lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[n * 2] += lazy[n];
	lazy[n * 2 + 1] += lazy[n];
	lazy[n] = 0;
}

void su(int l, int r, int v, int n, int s, int e)
{
	pr(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] += v; pr(n, s, e); return; }
	int m = s + e >> 1;
	su(l, r, v, n * 2, s, m);
	su(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

lli sq(int i, int n, int s, int e)
{
	pr(n, s, e);
	if (s > i || e < i) return 0;
	if (s == e) return seg[n];
	int m = s + e >> 1;
	if (i <= m) return sq(i, n * 2, s, m);
	else return sq(i, n * 2 + 1, m + 1, e);
}