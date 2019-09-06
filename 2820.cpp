#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 500'010;
int N, M, seg[4 * MAX], lazy[4 * MAX], rn[MAX], num[MAX], cnt, arr[MAX];
vector<int> adj[MAX];

void dfs(int u);
void pr(int n, int s, int e);
void su(int l, int r, int v, int n = 1, int s = 1, int e = N);
int sq(int i, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	cin >> arr[1];
	for (int i = 2; i <= N; ++i)
	{
		int v, p; cin >> v >> p;
		arr[i] = v; 
		adj[p].emplace_back(i);
	}
	dfs(1);
	for (int i = 1; i <= N; ++i)
		su(num[i], num[i], arr[i]);
	while (M--)
	{
		char f; int a, x;
		cin >> f;
		switch (f)
		{
		case 'p':
			cin >> a >> x;
			su(num[a] + 1, rn[a], x);
			break;
		case 'u':
			cin >> a;
			cout << sq(num[a]) << "\n";
		}
	}
}

void dfs(int u)
{
	num[u] = ++cnt;
	for (auto& v : adj[u])
		dfs(v);
	rn[u] = cnt;
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

int sq(int i, int n, int s, int e)
{
	pr(n, s, e);
	if (s > i || e < i) return 0;
	if (s == e) return seg[n];
	int m = s + e >> 1;
	if (i <= m) return sq(i, n * 2, s, m);
	else return sq(i, n * 2 + 1, m + 1, e);
}