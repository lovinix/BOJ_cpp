#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli arr[101]={0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 6; i <= 100; ++i)
		arr[i] = arr[i - 1] + arr[i - 5];
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		cout << arr[n] << "\n";
	}
}
