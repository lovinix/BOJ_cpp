#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pa = pair<lli, lli>;

int T, n;
pa arr[200001];
vector<pa> cvx;

int ccw(pa& p1, pa& p2, pa& p3);
bool cmp(pa& p1, pa& p2);
pa operator-(pa& p1, pa& p2);
lli dst(pa& p1, pa& p2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i].first >> arr[i].second;
		}
		swap(arr[0], *min_element(arr, arr + n));
		sort(arr + 1, arr + n, cmp);
		cvx.clear();
		cvx.emplace_back(arr[0]);
		cvx.emplace_back(arr[1]);
		for (int i = 2; i < n;)
		{
			if (cvx.size() < 2)
				cvx.emplace_back(arr[i++]);
			else
			{
				if (ccw(cvx[cvx.size() - 2], cvx[cvx.size() - 1], arr[i])>0)
					cvx.emplace_back(arr[i++]);
				else
					cvx.pop_back();
			}
		}
		lli ma = -1;
		pa z = { 0,0 };
		pa idx;
		for (int i = 0, j = 0; i < cvx.size(); ++i)
		{
			pa p1, p2;
			while (j + 1 < cvx.size() && ccw(z, p1 = cvx[i + 1] - cvx[i], p2 = cvx[j + 1] - cvx[j]) >= 0)
			{
				if (ma < dst(cvx[i], cvx[j]))
				{
					ma = dst(cvx[i], cvx[j]);
					idx.first = i;
					idx.second = j;
				}
				++j;
			}
			if (ma < dst(cvx[i], cvx[j]))
			{
				ma = dst(cvx[i], cvx[j]);
				idx.first = i;
				idx.second = j;
			}
		}
		cout << cvx[idx.first].first << " " << cvx[idx.first].second << " ";
		cout << cvx[idx.second].first << " " << cvx[idx.second].second << "\n";
	}
}

int ccw(pa& p1, pa& p2, pa& p3)
{
	lli t = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - p2.first * p1.second - p3.first * p2.second - p1.first * p3.second;
	return t < 0 ? -1 : t>0;
}

bool cmp(pa& p1, pa& p2)
{
	int t = ccw(arr[0], p1, p2);
	return t ? t > 0:(p1.first + p1.second < p2.first + p2.second);
}

pa operator-(pa& p1, pa& p2)
{
	return { p1.first - p2.first, p1.second - p2.second };
}

lli dst(pa& p1, pa& p2)
{
	return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}