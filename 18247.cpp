#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		if (M < 4 || N < 'L' - 'A' + 1) cout << "-1\n";
		else
		{
			cout << M * ('L'-'A') + 4 << '\n';
		}
	}
}