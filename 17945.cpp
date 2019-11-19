#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int A, B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> A >> B;
	int a = -A - sqrt(A * A - B);
	int b = -A + sqrt(A * A - B);
	if (a == b) cout << a;
	else cout << min(a,b) << " " << max(a,b);
}