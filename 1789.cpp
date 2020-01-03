#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> S;
	lli s = 0, cnt = 0;
	while (s <= S)
		s += ++cnt;
	cout << --cnt;
}