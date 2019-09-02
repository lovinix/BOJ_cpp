#include <bits/stdc++.h>
using namespace std;
using pii=pair<pair<int, int>, int>;

int N, M, arr[100'001], cnt[200'010], sqrtN, ans, num[200'010], res[200'010];
pii qu[100'001];

void add(int v);
void erase(int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (1)
	{
		cin >> N;
		if (!N) return 0;
		cin >> M;
		sqrtN = sqrt(N);
		memset(cnt, 0, sizeof cnt);
		memset(num, 0, sizeof num);
		memset(res, 0, sizeof res);
		ans = 0;
		for (int i = 1; i <= N; ++i)
		{
			cin >> arr[i];
			arr[i] += 100'001;
		}
		for (int i = 0; i < M; ++i)
		{
			cin >> qu[i].first.first >> qu[i].first.second;
			qu[i].second = i;
		}
		sort(qu, qu + M, [](pii& p1, pii& p2)
			{return p1.first.first / sqrtN == p2.first.first / sqrtN ?
			p1.first.second < p2.first.second :
			p1.first.first / sqrtN < p2.first.first / sqrtN; });
		int i = 1, j = 1;
		for (int z = 0; z < M; ++z)
		{
			while (j <= qu[z].first.second) add(arr[j++]);
			while (j > qu[z].first.second + 1) erase(arr[--j]);
			while (i < qu[z].first.first) erase(arr[i++]);
			while (i > qu[z].first.first) add(arr[--i]);
			res[qu[z].second] = ans;
		}
		for (int i = 0; i < M; ++i)
			cout << res[i] << "\n";
	}
}

void add(int v)
{
	if (cnt[v]) num[cnt[v]]--;
	cnt[v]++;
	num[cnt[v]]++;
	ans = max(ans, cnt[v]);
}

void erase(int v)
{
	num[cnt[v]]--;
	if (cnt[v] == ans && !num[cnt[v]]) ans--;
	cnt[v]--;
	num[cnt[v]]++;
}