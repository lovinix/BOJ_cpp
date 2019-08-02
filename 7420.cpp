#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using lli = long long;
using pa = pair<lli, lli>;

const double pi = 3.1415926535;

int N, L;
double ans;
pa arr[1001];
vector<pa> cvx;

lli ccw(pa& p1, pa& p2, pa& p3);
bool cmp(pa& p1, pa& p2);
lli dist(pa& p1, pa& p2);
lli dot(pa p1, pa p2);
pa operator-(pa& p1, pa& p2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i].X >> arr[i].Y;
	}
	swap(arr[0], *min_element(arr, arr + N));
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N;)
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
	int n = cvx.size();
	for (int i = 0; i < n; ++i)
	{
		pa prev = cvx[(i + n - 1) % n];
		pa now = cvx[i];
		pa next = cvx[(i + 1) % n];
		double d1 = sqrt(dist(now, next));
		ans += d1;
		double d2 = sqrt(dist(prev, now));
		lli inner = dot(prev - now, next - now);
		double theta = acos((double)inner / d1 / d2);
		theta = pi - theta;
		ans += L * theta;
	}
	cout << round(ans);
}

lli ccw(pa& p1, pa& p2, pa& p3)
{
	return p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y - p2.X * p1.Y - p3.X * p2.Y - p1.X * p3.Y;
}

bool cmp(pa& p1, pa& p2)
{
	lli t = ccw(arr[0], p1, p2);
	return t ? t > 0:(dist(arr[0], p1) < dist(arr[0], p2));
}

lli dist(pa& p1, pa& p2)
{
	return (p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y);
}

lli dot(pa p1, pa p2)
{
	return p1.X * p2.X + p1.Y * p2.Y;
}

pa operator-(pa& p1, pa& p2)
{
	return { p1.X - p2.X,p1.Y - p2.Y };
}