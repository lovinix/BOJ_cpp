#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using lli = long long;
using pa = pair<lli,lli>;

int n;
pa arr[10001];
vector<pa> cvx;

lli ccw(pa& p1, pa& p2, pa& p3);
bool cmp(pa& p1, pa& p2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].X >> arr[i].Y;
	}
	swap(arr[0], *min_element(arr, arr + n));
	sort(arr + 1, arr + n, cmp);
	cvx.emplace_back(arr[0]);
	cvx.emplace_back(arr[1]);
	for (int i = 2; i < n;)
	{
		if (cvx.size() < 2)
			cvx.emplace_back(arr[i++]);
		else
		{
			if (ccw(cvx[cvx.size() - 2], cvx[cvx.size() - 1], arr[i]) > 0)
				cvx.emplace_back(arr[i++]);
			else
				cvx.pop_back();
		}
	}
	lli ans = 0;
	for (int i = 1; i < cvx.size() - 1; ++i)
		ans += ccw(cvx[0], cvx[i], cvx[i+1]);
	cout << ans / 100;
}

lli ccw(pa& p1, pa& p2, pa& p3)
{
	return p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y - p2.X * p1.Y - p3.X * p2.Y - p1.X * p3.Y;
}

bool cmp(pa& p1, pa& p2)
{
	lli t = ccw(arr[0], p1, p2);
	return t ? t > 0:(p1.X + p1.Y < p2.X + p2.Y);
}