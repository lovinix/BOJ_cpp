#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	for (int i = 0; i <= s.length() / 2; ++i)
	{
		if (s[i] == '?' && s[s.length() - 1 - i] == '?')
			s[i] = s[s.length() - 1 - i] = 'a';
		if (s[i] == '?') s[i] = s[s.length() - 1 - i];
		if (s[s.length() - 1 - i] == '?') s[s.length() - 1 - i] = s[i];
	}
	cout << s;
}