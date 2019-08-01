#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pa = pair<lli, lli>;

int P, N;
pa arr[51];
vector<pa> cvx;

int ccw(pa& p1, pa& p2, pa& p3);
bool cmp(pa& p1, pa& p2);
bool operator<(pa& p1, pa& p2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> P;
	while (P--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i].first >> arr[i].second;
		}
		swap(arr[0], *min_element(arr, arr + N));
		sort(arr + 1, arr + N, cmp);
		cvx.clear();
		cvx.emplace_back(arr[0]);
		cvx.emplace_back(arr[1]);
		for (int i = 2; i < N;)
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
		pa cur = cvx[0];
		int idx = 0;
		for (int i = 0; i < cvx.size(); ++i)
		{
			if (cur < cvx[i])
			{
				cur = cvx[i];
				idx = i;
			}
		}
		cout << cvx.size() << "\n";
		cout << cvx[idx].first << " " << cvx[idx].second << "\n";
		for (int i = (idx - 1 + cvx.size())%cvx.size(); i != idx; i = (i + cvx.size() - 1) % cvx.size())
			cout << cvx[i].first << " " << cvx[i].second << "\n";
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

bool operator<(pa& p1, pa& p2)
{
	return p1.second == p2.second ? p1.first>p2.first : p1.second<p2.second;
}