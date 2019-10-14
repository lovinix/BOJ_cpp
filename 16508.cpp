#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Book
{
	int p, cnt[26]{ 0, };
	Book() {}
	Book(int _p, string& s)
	{
		p = _p;
		for (auto& c : s)
			cnt[c - 'A']++;
	}
};

int N, mask, ans=INT_MAX, cnt[26];
string T;
Book book[20];

void recv(int idx);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T >> N;
	for (auto& c : T) cnt[c - 'A']++;
	for (int i = 0; i < N; ++i)
	{
		int p; string s;
		cin >> p >> s;
		book[i] = Book(p, s);
	}
	recv(0);
	cout << (ans==INT_MAX?-1:ans);
}

void recv(int idx)
{
	if (idx == N)
	{
		int tmp[26], cur=0;
		for (int i = 0; i < 26; ++i) tmp[i] = cnt[i];
		for (int i = 0; i < N; ++i)
		{
			if (!(mask & 1 << i)) continue;
			cur += book[i].p;
			for (int j = 0; j < 26; ++j)
			{
				if (tmp[j] && book[i].cnt[j])
					tmp[j] -= min(tmp[j], book[i].cnt[j]);
	
			}
		}
		for (int i = 0; i < 26; ++i)
		{
			if (tmp[i]) return;
		}
		ans = min(ans, cur);
	}
	else
	{
		mask |= 1 << idx;
		recv(idx + 1);
		mask ^= 1 << idx;
		recv(idx + 1);
	}
}