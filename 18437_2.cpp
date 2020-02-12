#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int MOD = 100;
int N, M, ln[100'010], rn[100'010], num;
vector<int> adj[100'010];
bitset<100> bset[1100];

void dfs(int u, int p)
{
	ln[u] = ++num;
	for (auto& v : adj[u])
	{
		if (v == p) continue;
		dfs(v, u);
	}
	rn[u] = num;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int p; cin >> p;
		adj[p].emplace_back(i);
	}
	dfs(1, 0);
	for (int i = 0; i <= 1000; ++i)
		bset[i].set();
	cin >> M;
	while (M--)
	{
		int f, i, s, e, ans = 0;
		cin >> f >> i;
		switch (f)
		{
		case 1:
		case 2:
			s = ln[i] + 1, e = rn[i];
			if (s / MOD != e / MOD)
			{
				for (; s % MOD; ++s)
					bset[s / MOD].set(s % MOD, !(f - 1));
				for (; s + MOD <= e; s += MOD)
					f - 1 ? bset[s / MOD].reset() : bset[s / MOD].set();
			}
			for (; s <= e; ++s)
				bset[s / MOD].set(s % MOD, !(f - 1));
			break;
		case 3:
			s = ln[i] + 1, e = rn[i];
			if (s / MOD != e / MOD)
			{
				for (; s % MOD; ++s)
					ans += bset[s / MOD][s % MOD];
				for (; s + MOD <= e; s += MOD)
					ans += bset[s / MOD].count();
			}
			for(;s<=e;++s)
				ans += bset[s / MOD][s % MOD];
			cout << ans << "\n";
		}
	}
}