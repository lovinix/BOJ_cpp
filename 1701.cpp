#include <bits/stdc++.h>
using namespace std;

int pi[5001][5001];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int k = 0; k < s.length(); ++k)
	{
		for (int i = k+1, j = k; i < s.length(); ++i)
		{
			while (j > k && s[i] != s[j])
				j = pi[k][j - 1]+k;
			if (s[i] == s[j])
				pi[k][i] = ++j-k;
		}
	}
	int ans = 0;
	for(int i=0;i<s.length();++i)
	{
		for(int j=0;j<s.length();++j)
		{
			ans = max(ans, pi[i][j]);
		}
	}
	cout << ans;
}
