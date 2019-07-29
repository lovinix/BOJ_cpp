#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;
using lli = long long;

struct Trie
{
	bool f;
	pair<int, string> next[26]; int ch;
	Trie() : f(0), next{ {0,""} }, ch(0) {}
};

int N;
lli fac[30];
vector<Trie> trie(2);

void insert(string& s, int n = 1, int idx = 0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	trie.reserve(2 * N);
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		insert(s);
	}
	fac[0] = 1;
	for (int i = 1; i < 30; ++i)
		fac[i] = (fac[i - 1] * i) % MOD;
	lli ans = 1;
	for (auto& node : trie)
	{
		ans = (ans * fac[node.ch]) % MOD;
	}
	cout << ans;
}

void insert(string& s, int n, int idx)
{
	if (idx == s.length()) { trie[n].f = 1; ++trie[n].ch; return; }
	pair<int, string>& cur = trie[n].next[s[idx] - 'A'];
	if (!cur.first)
	{
		cur.first = trie.size();
		cur.second = s.substr(idx);
		++trie[n].ch;
		trie.emplace_back(Trie());
		insert(s, cur.first, s.length());
	}
	else
	{
		int i = 0;
		for (; i < min(s.length(), cur.second.length()); ++i)
		{
			if (s[idx+i] != cur.second[i])
				break;
		}
		string pfix = cur.second.substr(0, i);
		if (pfix == cur.second)
		{
			insert(s, cur.first, idx + cur.second.length());
		}
		else
		{
			int tmp = cur.first;
			cur.first = trie.size();
			trie.emplace_back(Trie());
			trie[cur.first].next[cur.second[i] - 'A'].first = tmp;
			trie[cur.first].next[cur.second[i] - 'A'].second = cur.second.substr(i);
			trie[cur.first].ch = 1;
			cur.second = pfix;
			insert(s, cur.first, idx + cur.second.length());
		}
	}
}