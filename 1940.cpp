#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	while (N--)
	{
		int v; cin >> v;
		if (m[M - v]) { m[M - v]--; ans++; }
		else m[v]++;
	}
	cout << ans;
}