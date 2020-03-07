#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K, B, A[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K >> B;
	for (int i = 0; i < B; ++i)
	{
		int v; cin >> v;
		A[v]++;
	}
	int ans = INT_MAX;
	for (int l = 1, r = 1, cnt = 0;;)
	{
		if (r - l < K)
		{
			if (r == N + 1) break;
			cnt += A[r++];
		}
		else
		{
			cnt -= A[l++];
		}
		if (r - l >= K) ans = min(cnt, ans);
	}
	cout << ans;
}