#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> s;
		if (s.length() != 7) { cout << "0\n"; continue; }
		if (s[0]!=s[2] && s[0] == s[1] && s[1] == s[4] && s[2] == s[3] && s[3] == s[5] && s[5] == s[6])
		{
			cout << "1\n"; continue;
		}
		cout << "0\n";
	}
}