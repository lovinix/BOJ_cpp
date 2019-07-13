#include <bits/stdc++.h>
using namespace std;

int arr[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		long long int ans = 0;
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				ans += gcd(arr[i], arr[j]);
			}
		}
		cout << ans << "\n";
	}
}