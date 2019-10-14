#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int C, N, dp[10010];
vector<pii> ini;

int recv(int c);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> C >> N;
	for (int i = 0; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		ini.emplace_back(v, u);
	}
	cout << recv(C);
}

int recv(int c)
{
	if (c <= 0) return 0;
	if (dp[c]) return dp[c];
	int ret = INT_MAX;
	for (auto& [i, v] : ini)
	{
		ret = min(ret, v + recv(c - i));
	}
	return dp[c] = ret;
}