#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
char ans[30];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N + N - 1; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); ++j)
			ans[j] ^= s[j];
	}
	cout << ans;
}