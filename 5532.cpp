#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int L, A, B, C, D;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> L >> A >> B >> C >> D;
	cout << L - (max(B / D + (B % D ? 1 : 0), A / C + (A % C ? 1 : 0)));
}