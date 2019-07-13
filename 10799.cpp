#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int cnt = 0;
	long long int ans = 0;
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '(')
			++cnt;
		else if (s[i - 1] == '(')
			ans += --cnt;
		else
		{
			--cnt;
			++ans;
		}
	}
	cout << ans;
}