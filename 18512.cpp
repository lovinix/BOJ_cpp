#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int X, Y, P1, P2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> X >> Y >> P1 >> P2;
	int cnt = 10000;
	while (cnt && P1 != P2)
	{
		if (P1 < P2) P1 += X;
		else P2 += Y;
		--cnt;
	}
	cout << (cnt == 0 ? -1 : P1);
}