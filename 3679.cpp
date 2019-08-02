#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using lli = long long;
using pa = pair<pair<lli, lli>, int>;

int c, n;
pa arr[2001];

int ccw(pa& p1, pa& p2, pa& p3);
bool cmp(pa& p1, pa& p2);
lli dist(pa& p1, pa& p2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c;
	while (c--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i].X.X >> arr[i].X.Y;
			arr[i].Y = i;
		}
		swap(arr[0], *min_element(arr, arr + n));
		sort(arr + 1, arr + n, cmp);
		int i = n - 1;
		for (; i > 0; --i)
		{
			if (ccw(arr[0], arr[i], arr[i - 1]))
				break;
		}
		reverse(arr + i, arr + n);
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i].Y << " ";
		}
		cout << "\n";
	}
}

int ccw(pa& p1, pa& p2, pa& p3)
{
	lli t = p1.X.X * p2.X.Y + p2.X.X * p3.X.Y + p3.X.X * p1.X.Y - p2.X.X * p1.X.Y - p3.X.X * p2.X.Y - p1.X.X * p3.X.Y;
	return t < 0 ? -1 : t>0;
}

bool cmp(pa& p1, pa& p2)
{
	int t = ccw(arr[0], p1, p2);
	return t ? t > 0:(dist(arr[0],p1)<dist(arr[0],p2));
}

lli dist(pa& p1, pa& p2)
{
	return (p1.X.X-p2.X.X) * (p1.X.X - p2.X.X) + (p1.X.Y - p2.X.Y) * (p1.X.Y - p2.X.Y);
}