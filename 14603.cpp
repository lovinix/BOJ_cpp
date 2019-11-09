#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, K, W, MID, seg[4 * 100'010], arr[310][310], ans[310][310];

void su(int i, int v, int n = 1, int s = 0, int e = K);
int sq(int k = MID, int n = 1, int s = 0, int e = K);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K >> W;
	MID = W * W / 2 + W % 2;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < W; ++i)
		for (int j = 1; j <= W; ++j)
			su(arr[i][j], 1);
	for (int i = 1; i + W - 1 <= N; ++i)
	{
		for (int j = (i & 1 ? 1 : M - W + 1); j <= (i & 1 ? W : M); ++j)
		{
			su(arr[i - 1][j], -1);
			su(arr[i + W - 1][j], 1);
		}
		ans[i][i & 1 ? 1 : M - W + 1] = sq();
		for (int j = (i & 1 ? 1 : M-W+1); (i & 1 ? j + W - 1 < M : j > 1); )
		{
			for (int k = i; k < i + W; ++k)
			{
				su(arr[k][j + (i & 1 ? 0 : W - 1)], -1);
				su(arr[k][j + (i & 1 ? W : -1)], 1);
			}
			ans[i][(i & 1 ? ++j : --j)] = sq();
		}
	}
	for (int i = 1; i + W - 1 <= N; ++i)
	{
		for (int j = 1; j + W - 1 <= M; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

void su(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n]+=v;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m) su(i, v, n * 2, s, m);
	else su(i, v, n * 2 + 1, m + 1, e);
}

int sq(int k, int n, int s, int e)
{
	if (s == e) return s;
	int m = s + e >> 1;
	if (k <= seg[n * 2]) return sq(k, n * 2, s, m);
	else return sq(k - seg[n * 2], n * 2 + 1, m + 1, e);
}