#include <bits/stdc++.h>
using namespace std;
using pii= pair<pair<int, int>,int>;

int N, M, arr[100'001], cnt[1'000'001], ans, res[100'001], sqrtN;
vector<pii> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	sqrtN = sqrt(N);
	for (int i = 1; i <= N; ++i) cin >> arr[i];
	cin >> M;
	q.resize(M);
	for (int i = 0; i < M; ++i) { cin >> q[i].first.first >> q[i].first.second; q[i].second = i; }
	sort(q.begin(), q.end(), [](pii& q1, pii& q2)
		{return q1.first.first / sqrtN == q2.first.first / sqrtN ? q1.first.second < q2.first.second : q1.first.first / sqrtN < q2.first.first / sqrtN; });
	int i = 1, j = 1;
	for (auto& qu : q)
	{
		while (j <= qu.first.second) ans += cnt[arr[j++]]++ ? 0 : 1;
		while (j > qu.first.second + 1) ans -= --cnt[arr[--j]] ? 0 : 1;
		while (i < qu.first.first)  ans -= --cnt[arr[i++]] ? 0 : 1;
		while (i > qu.first.first) ans += cnt[arr[--i]]++ ? 0 : 1;
		res[qu.second] = ans;
	}
	for (int i = 0; i < M; ++i)
		cout << res[i] << "\n";
}
