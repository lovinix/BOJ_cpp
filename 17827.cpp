#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, V, arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> V;
	int sz = N - V + 1;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	while (M--)
	{
		int K;
		cin >> K;
		K++;
		if (K <= V) cout << arr[K] << "\n";
		else
		{
			K -= V;
			K %= sz;
			cout << arr[V + K] << "\n";
		}
	}
}