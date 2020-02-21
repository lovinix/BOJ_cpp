#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, L, A[1010], B[1010], Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> L;
	for (int i = 1; i <= M; ++i)
	{
		cin >> B[i];
		A[i] = B[i] - B[i - 1];
	}
	A[M + 1] = L - B[M];
	while (N--)
	{
		cin >> Q;
		int l = 0, r = L, ans;
		while (l <= r)
		{
			int m = l + r >> 1;
			int cnt = 0;
			for (int i = 0, sum = 0; i <= M + 3; ++i)
			{
				sum += A[i];
				if (sum >= m) { ++cnt; sum = 0; }
			}
			if (cnt > Q) { ans = m; l = m + 1; }
			else r = m - 1;
		}
		cout << ans << "\n";
	}
}