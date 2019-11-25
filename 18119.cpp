#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int N, M, state[10'010][2];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		for (auto& c : s)
		{
			state[i][0] |= 1 << c - 'a';
		}
		state[i][1] = 0x3fffffff;
	}
	while (M--)
	{
		int f; char c;
		cin >> f >> c;
		int cnt = 0;
		int v = 1 << c - 'a';
		for (int i = 0; i < N; ++i)
		{
			if (f == 1) state[i][1] ^= v;
			else state[i][1] |= v;
			if ((state[i][1] & state[i][0]) == state[i][0]) ++cnt;
		}
		cout << cnt << '\n';
	}
}