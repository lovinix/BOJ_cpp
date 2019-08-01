#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using lli = long long;
using pa = pair<lli, lli>;

int N, sz;
bool used[10001];
pa pxpy;
vector<int> idx;
vector<pa> arr, cvx, nxt;

int ccw(pa& p1, pa& p2, pa& p3);
bool cmp(pa& p1, pa& p2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> pxpy.X >> pxpy.Y;
	arr.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i].X >> arr[i].Y;
	}
	
	while (arr.size() > 2)
	{
		swap(arr[0], *min_element(arr.begin(), arr.end()));
		sort(arr.begin() + 1, arr.end(), cmp);
		cvx.clear();
		memset(used, 0, sizeof(used));
		idx.clear();
		cvx.emplace_back(arr[0]);
		cvx.emplace_back(arr[1]);
		used[0] = 1; used[1] = 1;
		idx.push_back(0); idx.push_back(1);
		for (int i = 2; i < arr.size();)
		{
			if (cvx.size() < 2)
			{
				used[i] = 1;
				idx.push_back(i);
				cvx.emplace_back(arr[i++]);
			}
			else
			{
				if (ccw(cvx[cvx.size() - 2], cvx[cvx.size() - 1], arr[i]) >= 0)
				{
					used[i] = 1;
					idx.push_back(i);
					cvx.emplace_back(arr[i++]);
				}
				else
				{
					used[idx[idx.size() - 1]] = 0;
					idx.pop_back();
					cvx.pop_back();
				}
			}
		}
		for (int i = 0; i < cvx.size()-1; ++i)
		{
			if (ccw(cvx[i], cvx[i + 1], pxpy) <= 0)
			{
				cout << sz;
				return 0;
			}
		}
		for (int i = 0; i < arr.size(); ++i)
		{
			if (!used[i])
				nxt.emplace_back(arr[i]);
		}
		arr.clear();
		for (auto& p : nxt)
			arr.emplace_back(p);
		nxt.clear();
		++sz;
	}
	cout << sz;
}

int ccw(pa& p1, pa& p2, pa& p3)
{
	lli t = p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y - p2.X * p1.Y - p3.X * p2.Y - p1.X * p3.Y;
	return t < 0 ? -1 : t>0;
}

bool cmp(pa& p1, pa& p2)
{
	int t = ccw(arr[0], p1, p2);
	return t ? t > 0:(p1.X + p1.Y < p2.X + p2.Y);
}

