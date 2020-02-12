#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int MOD = 100;
int N, M;
bitset<100> bset[1100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int v; cin >> v;
		bset[i / MOD].set(i % MOD, v & 1);
	}
	cin >> M;
	while (M--)
	{
		int f, l, r;
		cin >> f >> l >> r;
		if (f == 1)
		{
			l--;
			bset[l / MOD].set(l % MOD, r & 1);
		}
		else
		{
			int s = --l, e = --r;
			int ans = 0;
			if (s / MOD != e / MOD)
			{
				for (; s % MOD; ++s)
					ans += bset[s / MOD][s % MOD];
				for (; s + MOD < e; s += MOD)
					ans += bset[s / MOD].count();
			}
			for (; s <= e; ++s)
				ans += bset[s / MOD][s % MOD];
			cout << (f == 2 ? r - l + 1 - ans : ans) << "\n";
		}
	}
}