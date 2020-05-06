#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int p[1'000'010];
lli N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 2; i*i <= 1'000'000; ++i)
	{
		if (p[i]) continue;
		for (int j = i + i; j <= 1'000'000; j += i)
		{
			p[j] = 1;
		}
	}
	lli ans = 1;
	for (int i = 2; i <= N; ++i)
	{
		if (p[i]) continue;
		lli tmp = i;
		while (tmp <= N) tmp *= i;
		tmp /= i;
		ans = (ans * tmp) % 987654321;
	}
	cout << ans;
}