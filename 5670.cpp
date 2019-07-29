#include <bits/stdc++.h>
using namespace std;

struct Trie
{
	bool f;
	int next[26], ch;
	Trie() : f(0), next{ 0 }, ch(0){}
};

int n;
double ans;
vector<Trie> trie;
string arr[(int)1e5 + 1];

void find(string& s, int n = 1, int idx = 0);
void insert(string& s, int n = 1, int idx = 0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (cin >> n)
	{
		trie.clear();
		ans = 0;
		for (int i = 0; i < 2; ++i) trie.emplace_back(Trie());
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			insert(arr[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			find(arr[i]);
		}
		cout << fixed << setprecision(2) << ans/n << "\n";
	}
}

void find(string& s, int n, int idx)
{
	if (idx == s.length()) return;
	if (trie[n].ch > 1 || (trie[n].ch==1&&trie[n].f) || idx == 0) ++ans;
	find(s, trie[n].next[s[idx] - 'a'], idx + 1);
}

void insert(string& s, int n, int idx)
{
	if (idx == s.length()) { trie[n].f = 1; return; }
	if (!trie[n].next[s[idx] - 'a'])
	{
		trie[n].next[s[idx] - 'a'] = trie.size();
		trie.emplace_back(Trie());
		++trie[n].ch;
	}
	insert(s, trie[n].next[s[idx] - 'a'], idx + 1);
}