#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> tree[4 * 100'001];

void u(int i, int v, int n = 1, int s = 1, int e = 1e5);
int q(int l, int r, int k, int n = 1, int s = 1, int e = 1e5);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int t;
		cin >> t;
		u(i, t);
	}
	for (int i = 0; i < 4 * 100'001; ++i)
		sort(tree[i].begin(), tree[i].end());
	cin >> Q;
	int ans = 0;
	while (Q--)
	{
		int i, j, k;
		cin >> i >> j >> k;
		i ^= ans; j ^= ans; k ^= ans;
		cout << (ans = q(i, j, k)) << "\n";
	}
}

void u(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	tree[n].push_back(v);
	if (s == e) return;
	int m = (s + e) / 2;
	u(i, v, 2 * n, s, m);
	u(i, v, 2 * n + 1, m + 1, e);
}

int q(int l, int r, int k, int n, int s, int e)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[n].end() - upper_bound(tree[n].begin(), tree[n].end(), k);
	int m = (s + e) / 2;
	return q(l, r, k, n * 2, s, m) + q(l, r, k, n * 2 + 1, m + 1, e);
}

