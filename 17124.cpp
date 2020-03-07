#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N, M, A[1'000'010], B[1'000'010];
lli ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; ++i) cin >> A[i];
		for (int i = 0; i < M; ++i) cin >> B[i];
		sort(B, B + M);
		ans = 0;
		for (int i = 0; i < N; ++i)
		{
			int idx = upper_bound(B, B + M, A[i]) - B;
			if (idx != M && idx != 0)
				ans += (abs(A[i] - B[idx]) < abs(A[i] - B[idx - 1]) ? B[idx] : B[idx - 1]);
			else
				ans += B[idx - (idx == M)];
		}
		cout << ans << "\n";
	}
}