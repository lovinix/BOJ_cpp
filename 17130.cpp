#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, Q, arr[300'001];
lli tree[300'001];

void u(int i, int v);
lli q(int i);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	fill(arr, arr + 2, 1);
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i)
		u(i+1, arr[i]);
	while (Q--)
	{
		int l, r;
		cin >> l >> r;
		cout << q(r) - q(l - 1) << "\n";
	}
}

void u(int i, int v)
{
	while (i <= N)
	{
		tree[i] += v;
		i += (i & -i);
	}
}

lli q(int i)
{
	lli ret = 0;
	while (i)
	{
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}