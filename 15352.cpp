#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Fan
{
	int v, l, r, ld, rd;
	Fan() : v(0), l(0), r(0), ld(1), rd(1) {}
};

int K, N, Q, seg[4 * 1'000'010];
lli ans;
Fan arr[1'000'010];

void u(int i, int n = 1, int s = 1, int e = N);
int q(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> K >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i].v; 
	for (int i = 1; i <= N; ++i)
	{
		int j = i;
		while (j <= N && arr[j].v == arr[i].v)
		{
			arr[j].l = i; ++j;
		}
		i = j - 1;
	}
	for (int i = N; i > 0; --i)
	{
		int j = i;
		while (j > 0 && arr[j].v == arr[i].v)
		{
			arr[j].r = i; --j;
		}
		i = j + 1;
	}
	cin >> Q;
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		if (a == 1)
		{
			if (arr[b - arr[b].ld].v == arr[b + arr[b].rd].v && arr[b - arr[b].ld].v != arr[b].v)
			{
				int l = arr[b - arr[b].ld].l, r = arr[b + arr[b].rd].r;
				for (int i = b-arr[b].ld; i >= l; --i)
					arr[i].r = r;
				for (int i = b+arr[b].rd; i <= r; ++i)
					arr[i].l = l;
			}
			arr[b - arr[b].ld].rd += arr[b].rd;
			arr[b + arr[b].rd].ld += arr[b].ld;
			u(b);
		}
		else
		{
			auto& [v, l, r, ld, rd] = arr[b];
			ans += (r - l + 1) - q(l, r);
		}
	}
	cout << ans;
}

void u(int i, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n]++;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m)
		u(i, n * 2, s, m);
	else
		u(i, n * 2 + 1, m + 1, e);
}

int q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return q(l, r, n * 2, s, m) + q(l, r, n * 2 + 1, m + 1, e);
}