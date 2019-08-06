#include <bits/stdc++.h>
#define MOD ((int)1e9+7)
using namespace std;
using lli = long long;

int N, M, K;
lli tree[4 * 1'000'001];

void u(int i, lli v, int n = 1, int s = 1, int e = N);
lli q(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i=1;i<=N;++i)
	{
		int v; cin >> v;
		u(i, v);
	}
	for(int i=0;i<M+K;++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) u(b, c);
		else cout << q(b, c) << "\n";
	}
}

void u(int i,lli v, int n, int s, int e)
{
	if (s == e) 
	{
		tree[n] = v; return;
	}
	int m = (s + e) >> 1;
	if (i <= m) u(i, v, n * 2, s, m);
	else u(i, v, n * 2 + 1, m + 1, e);
	tree[n] = tree[n * 2] * tree[n * 2 + 1] % MOD;
}

lli q(int l, int r, int n, int s, int e)
{
	if (e<l || s>r) return 1;
	if (l <= s && e <= r) return tree[n];
	int m = (s + e) >> 1;
	return q(l, r, n * 2, s, m) * q(l, r, n * 2 + 1, m + 1, e) % MOD;
}