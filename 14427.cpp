#include <bits/stdc++.h>
#define INF 1e9+1
using namespace std;
using pii = pair<int, int>;

int N, M, arr[100'001];
pii tree[4 * 100'001]{ {INF,-1} };

void u(int i, int v, int n = 1, int s = 1, int e = N);
pii q(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		u(i, arr[i]);
	}
	cin >> M;
	while (M--)
	{
		int f, a, b;
		cin >> f;
		if (f == 1) { cin >> a >> b; u(a, b); }
		else cout << q(1, N).second << "\n";
	}
}

void u(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	if (s == e) { tree[n] = { v,i }; arr[i] = v; return; }
	int m = (s + e) >> 1;
	u(i, v, n * 2, s, m);
	u(i, v, n * 2 + 1, m + 1, e);
	tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

pii q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return { INF,-1 };
	if (l <= s && e <= r) return tree[n];
	int m = (s + e) >> 1;
	return min(q(l, r, n * 2, s, m), q(l, r, n * 2 + 1, m + 1, e));
}