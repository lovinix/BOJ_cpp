#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, Q, t;
lli tree[300'001];

void u(int i, int v);
lli q(int i);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i=1;i<=N;++i)
	{
		cin >> t;
		u(i, (i & 1) ? t : -t);
	}
	while(Q--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) cout << abs(q(c) - q(b - 1)) << "\n";
		else u(b, (b & 1) ? c : -c);
	}
}

void u(int i, int v)
{
	while(i<=N)
	{
		tree[i] += v;
		i += i & -i;
	}
}

lli q(int i)
{
	lli ret = 0;
	while(i)
	{
		ret += tree[i];
		i -= i & -i;
	}
	return ret;
}