#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, X;
string ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> X;
	for(;N;N--)
	{
		if (N * 26 < X || N > X) { cout << "!"; return 0; }
		if (N * 26 == X) { while (N--) ans += 'Z'; cout << ans; return 0; }
		if ((N - 1) * 26 < X && N * 26 > X)
		{
			ans += (char)(X - (N - 1) * 26 - 1 + 'A');
			X -= ans.back() - 'A' + 1;
			continue;
		}
		ans += 'A';
		X--;
	}
	cout << ans;
}