#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pa = pair<lli, lli>;

int N;
pa arr[100001];
stack<pa> stk;


bool cmp(pa& p1, pa& p2);
int ccw(pa& p1, pa& p2, pa& p3);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	swap(arr[0], *min_element(arr,arr+N));
	sort(arr + 1, arr + N, cmp);
	stk.push(arr[0]);
	stk.push(arr[1]);
	for (int i = 2; i < N;)
	{
		if (stk.size() < 2)
		{
			stk.push(arr[i]);
			++i;
		}
		else
		{
			auto cur = stk.top();
			stk.pop();
			if (ccw(stk.top(), cur, arr[i]) > 0)
			{
				stk.push(cur);
				stk.push(arr[i]);
				++i;
			}
		}
	}
	cout << stk.size();
}

bool cmp(pa& p1, pa& p2)
{
	int t = ccw(arr[0], p1, p2);
	if (t) return t > 0;
	return (p1.first + p1.second) < (p2.first + p2.second);
}

int ccw(pa& p1, pa& p2, pa& p3)
{
	lli t = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - p2.first * p1.second - p3.first * p2.second - p1.first * p3.second;
	return t < 0 ? -1 : t>0;
}