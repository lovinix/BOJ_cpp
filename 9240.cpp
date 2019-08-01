#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pa = pair<lli, lli>;

int C;
pa arr[100001];
vector<pa> stk;

int ccw(pa& p1, pa& p2, pa& p3);
bool cmp(pa& p1, pa& p2);
pa operator-(const pa& p1, const pa& p2);
lli dst(pa& p1, pa& p2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	swap(arr[0], *min_element(arr, arr + C));
	sort(arr + 1, arr + C, cmp);
	stk.emplace_back(arr[0]);
	stk.emplace_back(arr[1]);
	for (int i = 2; i < C;)
	{
		if (stk.size() < 2)
		{
			stk.emplace_back(arr[i]);
			++i;
		}
		else
		{
			if (ccw(stk[stk.size()-2], stk[stk.size()-1], arr[i]) > 0)
			{
				stk.emplace_back(arr[i]);
				++i;
			}
			else
			{
				stk.pop_back();
			}
		}
	}
	pair<int, int> idx;
	pa z = { 0,0 };
	lli dist = -1;
	for (int i = 0, j = 0; i < stk.size(); ++i)
	{
		pa p1, p2;
		while (j + 1 < stk.size() && ccw(z, p1 = stk[i+1]-stk[i], p2 = stk[j+1]-stk[j]) >= 0)
		{
			if (dist < dst(stk[i], stk[j]))
			{
				dist = dst(stk[i], stk[j]);
				idx.first = i;
				idx.second = j;
			}
			++j;
		}
		if (dist < dst(stk[i], stk[j]))
		{
			dist = dst(stk[i], stk[j]);
			idx.first = i;
			idx.second = j;
		}
	}
	cout << fixed << setprecision(7) << sqrt(dst(stk[idx.first], stk[idx.second]));
}

int ccw(pa& p1, pa& p2, pa& p3)
{
	int t = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - p2.first * p1.second - p3.first * p2.second - p1.first * p3.second;
	return t < 0 ? -1 : t>0;
}

bool cmp(pa& p1, pa& p2)
{
	int t = ccw(arr[0], p1, p2);
	return t ? t > 0:(p1.first + p1.second < p2.first + p2.second);
}

pa operator-(const pa& p1, const pa& p2)
{
	return { p1.first - p2.first,p1.second - p2.second };
}

lli dst(pa& p1, pa& p2)
{
	return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}