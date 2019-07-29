#include <bits/stdc++.h>
using namespace std;

struct Trie
{
	bool f;
	int next[10];
	Trie() : f(0), next{ 0 } {}
};

int t, n;
vector<Trie> trie;
vector<string> arr[11];

int find(string& s, int n = 1, int idx = 0);
void insert(string& s, int n = 1, int idx = 0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--)
	{
		trie.clear();
		for (int i = 0; i < 2; ++i) trie.emplace_back(Trie());
		for (auto& v : arr)
			v.clear();
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			arr[s.length()].emplace_back(s);
		}
		for (int i = 1; i < 11; ++i)
		{
			for (auto& s : arr[i])
			{
				if (find(s))
				{
					cout << "NO\n";
					goto end;
				}
				insert(s);
			}
		}
		cout << "YES\n";
	end:;
	}
}

int find(string& s, int n, int idx)
{
	if (idx == s.length()) { return trie[n].f ? n : 0; }
	if (trie[n].f) return -1;
	if (trie[n].next[s[idx]-'0']) return find(s, trie[n].next[s[idx]-'0'], idx + 1);
	else return 0;
}

void insert(string& s, int n, int idx)
{
	if (idx == s.length()) { trie[n].f = 1; return; }
	if (!trie[n].next[s[idx] - '0'])
	{
		trie[n].next[s[idx] - '0'] = trie.size();
		trie.emplace_back(Trie());
	}
	insert(s, trie[n].next[s[idx] - '0'], idx + 1);
}