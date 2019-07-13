#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int k = n * n;
	int size = 0;
	for (int i = 0; i < k; ++i)
	{
		int t;
		cin >> t;
		if (size < n)
		{
			pq.push(t);
			++size;
		}
		else
		{
			pq.push(t);
			pq.pop();
		}
	}
	cout << pq.top();
}