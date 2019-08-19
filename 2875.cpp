#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int mn = min(n/2,m);
	k -= n - 2 * mn;
	k -= m - mn;
	while(k>0)
	{
		k -= 3; mn--;
	}
	cout << mn;
}
