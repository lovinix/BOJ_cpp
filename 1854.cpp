#include <bits/stdc++.h>
using namespace std;
using pa = pair<int, int>;

auto cmp = [&](pa & p1, pa & p2) {return p1.second > p2.second; };
int n, m, k;
priority_queue<pa, vector<pa>, decltype(cmp)> pq(cmp);
priority_queue<int> dist[1001];
vector<pa> arr[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].emplace_back(b, c);
	}
	pq.push({ 1,0 });
	//dist[1].push(0);
	while (!pq.empty())
	{
		int cur, d;
		tie(cur, d) = pq.top();
		pq.pop();
		for (auto& next : arr[cur])
		{
			if (dist[next.first].size() < k)
			{
				dist[next.first].push(d + next.second);
				pq.push({ next.first,d + next.second });
			}
			else
			{
				if (dist[next.first].top() > d + next.second)
				{
					dist[next.first].push(d + next.second);
					dist[next.first].pop();
					pq.push({ next.first,d + next.second });
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (dist[i].size() < k)
			cout << "-1\n";
		else
			cout << dist[i].top() << "\n";
	}
}