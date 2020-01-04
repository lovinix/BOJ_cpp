#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	while (s.length() % 3) s = "0" + s;
	string ans;
	for (int i = 0; i < s.length(); i += 3)
	{
		int t = 0;
		for (int j = i, k = 4; j <= i + 2; ++j,k/=2)
			if (s[j] == '1') t += k;
		ans += t + '0';
	}
	cout << ans;
}