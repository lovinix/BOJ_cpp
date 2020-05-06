#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
double A[] = { 350.34, 230.90, 190.55, 125.30, 180.90 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		auto ans = 0.0;
		for (int i = 0; i < 5; ++i)
		{
			double v;
			cin >> v;
			ans += v * A[i];
		}
		cout << "$" << fixed << setprecision(2) << ans << '\n';
	}
}