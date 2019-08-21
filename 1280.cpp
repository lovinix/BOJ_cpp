#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")
#define MOD 1'000'000'007
#define MAX 200'001
using namespace std;
using lli = long long;
using pil = pair<int, lli>;

int N;
lli ans=1, acc = 0;
pil tree[MAX+1];

void u(int i);
pil q(int i);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i=1;i<=N;++i)
	{
		lli t;
		cin >> t;
		t++;
		if(i>1)
		{
			lli sum = 0;
			pil l = q(t), r = { i - 1 - l.first,acc - l.second };
			sum += t * l.first - l.second;
			sum += r.second - t * r.first;
			sum %= MOD;
			ans *= sum;
			ans %= MOD;
		}
		u(t);
		acc += t;
	}
	cout << ans;
}

void u(int i)
{
	int v = i;
	while(i<=MAX)
	{
		tree[i].first++;
		tree[i].second += v;
		i += i & -i;
	}
}


pil q(int i)
{
	pil ret = {0,0};
	while(i)
	{
		ret.first += tree[i].first;
		ret.second += tree[i].second;
		i -= i & -i;
	}
	return ret;
}