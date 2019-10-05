#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int bias = 10'000;
int N, seg[4*100'010];

void u(int i, int n = 1, int s = 0, int e = 20'000);
int q(int k, int n = 1, int s = 0, int e = 20'000);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int v; cin >> v;
		u(v + bias);
		cout << q(i / 2 + 1) - bias << "\n";
	}
}

void u(int i, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n]++;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m) u(i, n * 2, s, m);
	else u(i, n * 2 + 1, m + 1, e);
}

int q(int k, int n, int s, int e)
{
	if (s == e) return s;
	int m = s + e >> 1;
	if (seg[n * 2] >= k) return q(k, n * 2, s, m);
	else return q(k - seg[n * 2], n * 2 + 1, m + 1, e);
}