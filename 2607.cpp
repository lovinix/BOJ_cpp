#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Word
{
	int num = 0, cnt[26]{ 0 };
	Word(string s)
	{
		for (auto& c : s) num++, cnt[c - 'A']++;
	}
	int operator-(Word& w)
	{
		int ret = 0;
		for (int i = 0; i < 26; ++i) ret += abs(cnt[i] - w.cnt[i]);
		return ret;
	}
};

int N, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	string s; cin >> s;
	Word w(s);
	while (--N)
	{
		string t; cin >> t;
		Word x(t);
		if ((w.num - x.num == 0 && w - x <= 2) || (abs(w.num - x.num) == 1 && w - x < 2))
			++ans;
	}
	cout << ans;
}