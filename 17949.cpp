#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long;

int N;
lli ans[500'010];
string s, arr[500'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s >> N;
	int k = N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	while (N--)
	{
		string t = arr[N];
		int cnt = t[0] == 'c' ? 2 : t[0] == 'i' ? 8 : 16;
		lli tmp = 0;
		for (lli v = 1; cnt; cnt--, v *= 16, s.pop_back())
			tmp += v * (s.back() >= 'a' ? s.back() - 'a' + 10 : s.back() - '0');
		ans[N] = tmp;
	}
	for (int i = 0; i < k; ++i)
		cout << ans[i] << " ";
}