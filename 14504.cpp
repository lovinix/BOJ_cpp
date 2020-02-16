#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, A[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	cin >> M;
	while (M--)
	{
		int f, i, j, k;
		cin >> f >> i >> j;
		if (f == 2)
		{
			int ans = 0;
			cin >> k;
			for (; i <= j; ++i)
				if (A[i] > k) ++ans;
			cout << ans << '\n';
		}
		else
			A[i] = j;
	}
}