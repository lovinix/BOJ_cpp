#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int L, P, V;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for(int t=1;cin >> L >> P >> V;cout<<"Case "<<t++<<": "<<(V/P)*L + min(V%P,L)<<"\n")
		if (L == 0 && P == 0 && V == 0) return 0;
}