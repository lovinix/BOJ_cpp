#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using lli = long long;
using pii = pair<pair<lli, lli>,int>;

int N, ans[1001], fl=1, idx;
deque<pii> deq;
vector<pii> cvx;

int ccw(pii& p1, pii& p2, pii& p3);
lli dist(pii& p1, pii& p2);
bool cmp(pii& p1, pii& p2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		lli x, y;
		cin >> x >> y;
		deq.push_back({{x,y},i});
	}
	while (deq.size() > 2)
	{
		swap(deq[0], *min_element(deq.begin(), deq.end()));
		sort(deq.begin() + 1, deq.end(), cmp);
		cvx.clear();
		int len = deq.size();
		idx = 0;
		while (idx<len)
		{
			if (cvx.size() < 2)
				cvx.push_back(deq.front()), deq.pop_front(), ++idx;
			else
			{
				if (ccw(cvx[cvx.size() - 2], cvx[cvx.size() - 1], deq.front()) > 0)
					cvx.push_back(deq.front()), deq.pop_front(), ++idx;
				else
				{
					deq.push_back(cvx[cvx.size() - 1]);
					cvx.pop_back();
				}
			}
		}
		if (cvx.size() > 2)
		{
			for (auto& p : cvx)
			{
				ans[p.Y] = fl;
			}
		}
		++fl;
	}
	for (int i = 0; i < N; ++i)
	{
		cout << ans[i] << " ";
	}
	
}

int ccw(pii& p1, pii& p2, pii& p3)
{
	lli t = p1.X.X * p2.X.Y + p2.X.X * p3.X.Y + p3.X.X * p1.X.Y - p2.X.X * p1.X.Y - p3.X.X * p2.X.Y - p1.X.X * p3.X.Y;
	return t < 0 ? -1 : t>0;
}

lli dist(pii& p1, pii& p2)
{
	return (p1.X.X - p2.X.X) * (p1.X.X - p2.X.X) + (p1.X.Y - p2.X.Y) * (p1.X.Y - p2.X.Y);
}

bool cmp(pii& p1, pii& p2)
{
	int t = ccw(deq[0], p1, p2);
	return t ? t > 0:dist(deq[0], p1) < dist(deq[0], p2);
}