#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;
using tu = tuple<int, int, int, int>;

int N, arr[100'001], M, q1m, q2m;
lli tree[4 * 100'001], ans[100'001];
pii q1[100'001];
tu q2[100'001];

void u(int i, int v, int n = 1, int s = 1, int e = N);
lli q(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		u(i, arr[i]);
	}
	cin >> M;
	for(int z=0;z<M;++z)
	{
		int f, k, i, j, v;
		cin >> f;
		if (f == 1)
		{
			cin >> i >> v;
			q1[++q1m] = { i,v };
		}
		else
		{
			cin >> k >> i >> j;
			q2[q2m] = { k,i,j,q2m };
			++q2m;
		}
	}
	sort(q2, q2 + q2m);
	for (int i = 0,j = 0; i <= q1m; ++i)
	{
		if (i != 0)
		{
			u(q1[i].first, q1[i].second - arr[q1[i].first]);
			arr[q1[i].first] = q1[i].second;
		}
		while (get<0>(q2[j]) == i)
		{
			auto [k, l, r, idx] = q2[j];
			ans[idx] = q(l, r);
			++j;
		}
	}
	for (int i = 0; i < q2m; ++i)
		cout << ans[i] << "\n";
}

void u(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	tree[n] += v;
	if (s == e) return;
	int m = s + e >> 1;
	u(i, v, n * 2, s, m);
	u(i, v, n * 2 + 1, m + 1, e);
}

lli q(int l, int r, int n, int s, int e)
{
	if (e<l || s>r) return 0;
	if (l <= s && e <= r) return tree[n];
	int m = s + e >> 1;
	return q(l, r, n * 2, s, m) + q(l, r, n * 2 + 1, m + 1, e);
}