#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

class Pq
{
public:
	int arr[400'010], size;
	Pq() :arr{ 0 }, size(1){}
	void push(int v)
	{
		arr[size] = v;
		for (int idx = size; idx / 2 && arr[idx / 2] < arr[idx]; idx /= 2)
			swap(arr[idx], arr[idx / 2]);
		++size;
	}
	int top() { return size>1?arr[1]:0; }
	void pop()
	{
		if (size <= 1) return;
		swap(arr[1], arr[--size]);
		for (int idx = 1;;)
		{
			int lc = idx * 2 < size ? idx * 2 : 0;
			int rc = idx * 2 + 1 < size ? idx * 2 + 1 : 0;
			if (arr[idx] > arr[lc] && arr[idx] > arr[rc]) break;
			idx = arr[lc] > arr[rc] ? lc : rc;
			swap(arr[idx / 2], arr[idx]);
		}
	}
};

int N;
Pq pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--)
	{
		int x; cin >> x;
		if (x) pq.push(x);
		else { cout << pq.top() << "\n"; pq.pop(); }
	}
}