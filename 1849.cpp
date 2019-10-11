#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, seg[4*100'010], ans[100'010];

void u(int i, int v, int n = 1, int s = 1, int e = N);
int q(int k, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		u(i, 1);
	for (int i = 1; i <= N; ++i)
	{
		int k; cin >> k;
		++k;
		int kth = q(k);
		ans[kth] = i;
		u(kth, -1);
	}
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << "\n";
}

void u(int i, int v, int n, int s, int e)
{
	if (i<s || e<i) return;
	seg[n]+=v;
	if (s == e) return;
	int m = s + e >> 1;
	u(i, v, n * 2, s, m);
	u(i, v, n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int q(int k, int n, int s, int e)
{
	if (s == e) return s;
	int m = s + e >> 1;
	if (seg[n * 2] >= k) return q(k, n * 2, s, m);
	else return q(k - seg[n * 2], n * 2 + 1, m + 1, e);
}