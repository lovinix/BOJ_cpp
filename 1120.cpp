#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a, b;
	cin >> a >> b;
	int mn = 123456;
	for(int i=0;i<=b.length()-a.length();++i)
	{
		int cnt = 0;
		for (int j = 0, k = i; j < a.length() && k < b.length(); ++j, ++k)
			if (b[k] != a[j]) cnt++;
		mn = min(mn, cnt);
	}
	cout << mn;
}
