#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli a, b, c;
	while(cin>>a>>b>>c)
	{
		if (a == 0) return 0;
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);
		if (c * c == a * a + b * b) cout << "right\n";
		else cout << "wrong\n";
	}
}
