#include <bits/stdc++.h>
using namespace std;

int N, ans, b;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s;
	for(int i=0;i<s.length();++i)
	{
		if (s[i] == 'X') b = 0;
		else ans += i + 1 + b++;
	}
	cout << ans;
}
