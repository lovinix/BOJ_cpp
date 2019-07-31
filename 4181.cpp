#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pa = pair<lli, lli>;

int n,N;
pa arr[100001];
stack<pa> stk;

int ccw(pa& p1, pa& p2, pa& p3);
bool cmp(pa& p1, pa& p2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		lli x, y; char c;
		cin >> x >> y >> c;
		if (c == 'Y')
		{
			arr[N].first = x;
			arr[N].second = y;
			++N;
		}
	}
	swap(arr[0], *min_element(arr, arr + N));
	sort(arr + 1, arr + N, cmp);
	int i = N - 1;
	for (; i > 0; --i)
	{
		if (ccw(arr[0], arr[i], arr[i - 1]))
			break;
	}
	reverse(arr + i, arr + N);
	cout << N << "\n";
	for (i = 0; i < N; ++i)
		cout << arr[i].first << " " << arr[i].second << "\n";
}

int ccw(pa& p1, pa& p2, pa& p3)
{
	lli t = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - p2.first * p1.second - p3.first * p2.second - p1.first * p3.second;
	return t < 0 ? -1 : t>0;
}

bool cmp(pa& p1, pa& p2)
{
	int t = ccw(arr[0], p1, p2);
	if (t) return t > 0;
	return (p1.first + p1.second) < (p2.first + p2.second);
}