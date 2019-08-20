#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, L, t;
deque<pii> deq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L;
	for(int i=0;i<N;++i)
	{
		cin >> t;
		while (!deq.empty() && (deq.front().second >= t || deq.front().first < i - L + 1))
			deq.pop_front();
		while (!deq.empty() && (deq.back().second >= t || deq.back().first < i - L + 1))
			deq.pop_back();
		deq.emplace_back(i, t);
		cout << deq.front().second << " ";
	}
}
