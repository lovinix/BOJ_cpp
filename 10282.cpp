#include <bits/stdc++.h>
#define INF 1234567890
using namespace std;
using pa = pair<int,int>;

int n, d, c, dist[10001];
vector<pa> arr[10001];
auto cmp = [&](pa a, pa b) {return a.second > b.second; };
priority_queue<pa, vector<pa>, decltype(cmp)> pq(cmp);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		cin >> n >> d >> c;
		for (int i = 0; i <= n; ++i)
			arr[i].clear();
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < d; ++i)
		{
			int a, b, s;
			cin >> a >> b >> s;
			arr[b].push_back({ a,s });
		}
		for (int i = 0; i <= n; ++i)
			dist[i] = INF;
		dist[c] = 0;
		pq.push({ c,0 });
		while (!pq.empty())
		{
			auto [y, z] = pq.top();
			pq.pop();
			for (auto next : arr[y])
			{
				if (dist[next.first] <= z + next.second) continue;
				dist[next.first] = z + next.second;
				pq.push({ next.first, z + next.second });
			}
		}
		int a=0, b = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (dist[i] != INF)
			{
				++a; 
				b = max(b, dist[i]);
			}
		}
		cout << a << " " << b << "\n";
	}
}