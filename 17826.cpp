#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int arr[51];
string ans[51];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 5; ++i) ans[i] = "A+";
	for (int i = 6; i <= 15; ++i) ans[i] = "A0";
	for (int i = 16; i <= 30; ++i) ans[i] = "B+";
	for (int i = 31; i <= 35; ++i) ans[i] = "B0";
	for (int i = 36; i <= 45; ++i) ans[i] = "C+";
	for (int i = 46; i <= 48; ++i) ans[i] = "C0";
	for (int i = 49; i <= 50; ++i) ans[i] = "F";
	for (int i = 0; i < 50; ++i) cin >> arr[i];
	reverse(arr, arr + 50);
	int v; cin >> v;
	cout << ans[50 - (lower_bound(arr, arr + 50, v) - arr)];
}