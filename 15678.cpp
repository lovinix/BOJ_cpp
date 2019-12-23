#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pli = pair<lli, int>;

int N, D, arr[100'010];
lli dp[100'010];
priority_queue<pli> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> D;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	pq.emplace(0, 0);
	for (int i = 1; i <= N; ++i)
	{
		while (pq.size() && pq.top().second < i - D)
			pq.pop();
		dp[i] = max(0LL, pq.top().first) + arr[i];
		pq.emplace(dp[i], i);
	}
	lli ans = LLONG_MIN;
	for (int i = 1; i <= N; ++i)
		ans = max(ans, dp[i]);
	cout << ans;
}