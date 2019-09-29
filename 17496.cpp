#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, T, C, P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> T >> C >> P;
	int ans = 0;
	for (int i = 1 + T; i <= N; i += T)
		ans += C * P;
	cout << ans;
}