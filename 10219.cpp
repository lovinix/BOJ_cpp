#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, H, W;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> H >> W;
		for (int i = 0; i < H; ++i)
		{
			string s;
			cin >> s;
			reverse(s.begin(), s.end());
			cout << s << "\n";
		}
	}
}