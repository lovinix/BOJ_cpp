#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long;

int N;
lli Q, P, K, C;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	lli ans = ULLONG_MAX;
	int idx;
	for(int i=1;i<=N;++i)
	{
		cin >> P >> K >> C;
		lli A = Q / K + (Q % K ? 0 : -1);
		lli cur = (A * (A + 1) / 2) * C + P;
		if (ans > cur) { ans = cur; idx = i; }
	}
	cout << idx << " " << ans;
}