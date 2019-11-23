#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int ans;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;

	for (int l = 0; l < s.length(); ++l)
	{
		for (int d = 1; l + d + d <= s.length(); ++d)
		{
			int suml = 0, sumr = 0;
			for (int k = 0; k < d; ++k)
				suml += s[l+k]-'0';
			for (int k = d; k < 2 * d; ++k)
				sumr += s[l+k]-'0';
			if (suml == sumr) ans = max(ans, 2*d);
		}
	}

	cout << ans;
}