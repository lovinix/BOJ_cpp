#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[10], dp[61][61][61];

int recv(int a, int b, int c);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	cout << recv(arr[0], arr[1], arr[2]);
}

int recv(int a, int b, int c)
{
	a = max(0, a); b = max(0, b); c = max(0, c);
	if (a == 0 && b == 0 && c == 0) return 0;
	if (dp[a][b][c]) return dp[a][b][c];
	return dp[a][b][c] = min({ recv(a - 9,b - 3,c - 1),recv(a - 9,b - 1,c - 3),recv(a - 3,b - 9,c - 1),recv(a - 3,b - 1,c - 9),recv(a - 1,b - 9,c - 3),recv(a - 1,b - 3,c - 9) }) + 1;
}