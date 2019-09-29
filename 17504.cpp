#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
lli arr[20];

lli gcd(lli a, lli b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	lli c = 1, p = arr[N - 1];
	for (int i = N - 2; i >= 0; --i)
	{
		c += p * arr[i];
		lli g = gcd(c, p);
		c /= g;
		p /= g;
		swap(c, p);
	}
	c = p - c;
	lli g = gcd(c, p);
	c /= g;
	p /= g;
	cout << c << " " << p;
}


lli gcd(lli a, lli b)
{
	if (a < b) swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}