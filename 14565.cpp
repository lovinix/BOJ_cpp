#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli N, A;

lli egcd(lli a, lli b, lli& x, lli& y);
bool canon_egcd(lli a, lli b, lli c, lli& x, lli& y);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> A;
	cout << N - A << " ";
	lli c, q;
	bool f = canon_egcd(A, N, 1, c, q);
	if (f) cout << c;
	else cout << -1;

}

lli egcd(lli a, lli b, lli& x, lli& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	lli d = egcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

bool canon_egcd(lli a, lli b, lli c, lli& x, lli& y)
{
	int d = egcd(a, b, x, y);
	if (c % d) return 0;
	y = ((-y * c / d) % (a / d) + (a / d)) % (a / d);
	x = (c + b * y) / a;
	return 1;
}
