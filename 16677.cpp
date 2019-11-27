#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
double mx;
string s, t, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s >> T;
	while (T--)
	{
		int v, c = 0, i, j;
		cin >> t >> v;
		for (i = j = 0; i < s.length() && j < t.length(); ++j)
			if (s[i] == t[j]) ++i;
			else ++c;
		if (i < s.length()) continue;
		c += t.length() - j;
		if (mx < 1.0 * v / c) { mx = 1.0 * v / c; ans = t; }
	}
	cout << (ans == "" ? "No Jam" : ans);
}