#include <bits/stdc++.h>
#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

vector<vector<pair<int, int>>> arr;
bool isvisited[100001];
queue<int> q;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		arr.emplace_back(vector<pair<int, int>>());
	}
	int mi = (int)1e9; int ma = -1;
	for (int i = 0; i < M; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		arr[u-1].emplace_back(make_pair(v-1,c));
		arr[v - 1].emplace_back(make_pair(u - 1, c));
		mi = min(mi, c);
		ma = max(ma, c);
	}
	int st, ed;
	cin >> st >> ed;
	--st; --ed;
	int l = mi, r = ma;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		bool f = false;
		while (!q.empty())
			q.pop();
		memset(isvisited, 0, sizeof(isvisited));
		q.push(st);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			if (cur == ed)
			{
				ans = mid;
				l = mid + 1;
				f = true;
				break;
			}
			for (auto& v : arr[cur])
			{
				if (isvisited[v.first]) continue;
				if (mid > v.second) continue;
				isvisited[v.first] = true;
				q.push(v.first);
			}
		}
		if (f)
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;

}