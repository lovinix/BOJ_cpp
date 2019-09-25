#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int K, stk[100'010], cnt = 0, tmp;
lli ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> K;
	while (K--)
	{
		cin >> tmp;
		if (!tmp) ans -= stk[--cnt];
		else stk[cnt++] = tmp, ans += tmp;
	}
	cout << ans;
}