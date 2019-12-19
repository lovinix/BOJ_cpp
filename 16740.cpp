#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pli = pair<lli, int>;

int N, ans, A[5010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	sort(A, A + N);
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			lli dif = A[j]- A[i];
			int len = 2, idx=j;
			while(1)
			{
				int next = lower_bound(A + idx, A + N, A[idx] + dif) - A;
				if (next == N || A[next] != A[idx] + dif) break;
				idx = next;
				len++;
			}
			ans = max(ans, len);
		}
	}
	cout << ans;
}