#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#define MOD (int)1e9+7;
using namespace std;
using lli = long long;

struct Trie
{
	bool f;
	int next[26], ch;
	Trie() : f(0), next{ 0 }, ch(0) {}
};

int N;
lli dp[200001];
string s;
vector<Trie> trie(2);

pair<int,int> find(string& s, int n, int idx, int e);
void insert(string& s, int n = 1, int idx = 0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string t;
		cin >> t;
		insert(t);
	}
	cin >> s;
	dp[0] = 1;
	for (int i = 0; i <= s.length(); ++i)
	{
		int root = 1;
		for (int j = i + 1; j <= s.length() && j <= i + 300; ++j)
		{
			pair<int, int> tmp = find(s, root, j-1, j);
			dp[j] += dp[i] * tmp.first;
			dp[j] %= MOD;
			if (tmp.second == 0) break;
			root = tmp.second;
		}
	}
	cout << dp[s.length()];
	return 0;
}

pair<int,int> find(string& s, int n, int idx, int e)
{
	if (idx == e || idx == s.length())
	{
		if (idx == e) return { trie[n].ch,n };
		else return { 0,0 };
	}
	if (!trie[n].next[s[idx] - 'a'])
		return { 0,0 };
	return find(s, trie[n].next[s[idx] - 'a'], idx + 1, e);
}

void insert(string& s, int n, int idx)
{
	if (idx == s.length()) { trie[n].f = 1; ++trie[n].ch; return; }
	if (!trie[n].next[s[idx] - 'a'])
	{
		trie[n].next[s[idx] - 'a'] = trie.size();
		trie.emplace_back(Trie());
	}
	++trie[n].ch;
	insert(s, trie[n].next[s[idx] - 'a'], idx + 1);
}