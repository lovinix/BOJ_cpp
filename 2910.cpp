#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, C, A[1010];
map<int, int> m, pos;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> C;
	for_each(A, A + N, [](int& a) {cin >> a; m[a]++; if (pos[a] == 0) pos[a] = INT_MAX; pos[a] = min(pos[a], (int)(&a - A + 1)); });
	sort(A, A + N, [](const int& a, const int& b) {
		if (auto ma = m[a], mb = m[b]; ma == mb)
			return pos[a] < pos[b];
		else return ma > mb;
		});
	for_each(A, A + N, [](int& a) {cout << a << " "; });
}