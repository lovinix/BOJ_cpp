#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int A[200'010];
string s, tmp;

void mana(string& s, int N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> tmp;
	for (auto& c : tmp)
		s += '#', s += c;
	s += '#';
	mana(s, s.length());
	int ans = 0;
	for (int i=0;i<s.length();++i)
		ans = max(ans, A[i]);
	cout << ans;
}

void mana(string& s, int N)
{
	int r = 0, p = 0;
	for (int i = 0; i < N; ++i)
	{
		if (i <= r)
			A[i] = min(A[2 * p - i], r - i);
		else
			A[i] = 0;
		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && s[i - A[i] - 1] == s[i + A[i] + 1])
			A[i]++;
		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}
	}
}