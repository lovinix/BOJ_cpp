#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, seg[4 * 500'001], arr[500'001];

void init(int n = 1, int s = 1, int e = N);
void u(int i, int v, int n = 1, int s = 1, int e = N);
int q(int k, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	init();
	cin >> M;
	while (M--)
	{
		int f, i, a;
		cin >> f;
		switch (f)
		{
		case 1:
			cin >> i >> a;
			u(i, a);
			break;
		case 2:
			cin >> i;
			cout << q(i) << "\n";
		}
	}
}

void init(int n, int s, int e)
{
	if (s == e) { seg[n] = arr[s]; return; }
	int m = s + e >> 1;
	init(n * 2, s, m);
	init(n * 2 + 1, m + 1, e);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void u(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n] += v;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m) u(i, v, n * 2, s, m);
	else u(i, v, n * 2 + 1, m + 1, e);
}

int q(int k, int n, int s, int e)
{
	if (s == e) return s;
	int m = s + e >> 1;
	if (seg[n * 2] >= k) return q(k, n * 2, s, m);
	else return q(k - seg[n * 2], n * 2 + 1, m + 1, e);
}