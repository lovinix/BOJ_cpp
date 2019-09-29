#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, Q, st, arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	while (Q--)
	{
		int f, i, x, s;
		cin >> f;
		switch (f)
		{
		case 1:
			cin >> i >> x;
			arr[(st + i - 1) % N] += x;
			break;
		case 2:
			cin >> s;
			st = (st - s + N) % N;
			break;
		case 3:
			cin >> s;
			st = (st + s) % N;
		}
	}
	for (int i = 0; i < N; ++i) 
		cout << arr[(st + i) % N] << " ";
}