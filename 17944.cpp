#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> T;
	for (int i = 1; i < 2 * N; ++i)
		arr.emplace_back(i);
	for (int i = 2 * N; i > 1; --i)
		arr.emplace_back(i);
	T--;
	T %= arr.size();
	cout << arr[T];
}