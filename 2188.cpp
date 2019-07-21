#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, c[402][402], f[402][402], p[402];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int src = 0, snk = 401;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			int k;
			cin >> k;
			c[i][k+200] = 1;
			c[k+200][snk] = 1;
		}
		c[src][i] = 1;
	}
	int ans = 0;
	while (true)
	{
		memset(p, -1, sizeof(p));
		while (!q.empty()) q.pop();
		q.push(src);
		p[src] = src;
		while (!q.empty() && p[snk] == -1)
		{
			int cur = q.front();
			q.pop();
			for (int next = src; next <= snk; ++next)
			{
				if (c[cur][next] - f[cur][next] > 0 && p[next] == -1)
				{
					p[next] = cur;
					q.push(next);
				}
			}
		}
		if (p[snk] == -1) break;
		int m = 1;
		for (int cur = snk; cur != src; cur = p[cur])
		{
			f[p[cur]][cur] += m;
			f[cur][p[cur]] -= m;
		}
		ans += m;
	}
	cout << ans;
}