#include <bits/stdc++.h>
#define SZ 4
using namespace std;

struct Trie
{
	int f, next[26];
	Trie() : f(0), next{ 0 } {}
};

int w, b, dn[] = { 1,1,0,-1,-1,-1,0,1 }, dm[] = { 0,-1,-1,-1,0,1,1,1 };
int sc[] = { 0,0,0,1,1,2,3,5,11 }, score, num;
bool visit[4][4];
vector<Trie> trie(2);
char arr[10][10];
string word;

void dfs(int n, int m, string& s);
int find(string& s, int n = 1, int idx = 0);
void insert(string& s, int n = 1, int idx = 0);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> w;
	for (int i = 0; i < w; ++i)
	{
		string t;
		cin >> t;
		insert(t);
	}
	cin >> b;
	while (b--)
	{
		score = num = 0; word = "";
		for (int i = 0; i < 4; ++i)
			cin >> arr[i];
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				string s = "";
				dfs(i, j, s);
			}
		}
		cout << score << " " << word << " " << num << "\n";
	}
}

void dfs(int n, int m, string& s)
{
	if (s.length() == 8) return;
	visit[n][m] = 1;
	s += arr[n][m];
	int idx = find(s);
	if (idx != b && idx != 0)
	{
		score += sc[s.length()];
		num++;
		if (word.length() < s.length()) word = s;
		else if (word.length() == s.length()) word = min(word, s);
	}
	for (int i = 0; i < 8; ++i)
	{
		int nn = n + dn[i], nm = m + dm[i];
		if (nn < 0 || nm < 0 || nn == SZ || nm == SZ) continue;
		if (visit[nn][nm]) continue;
		dfs(nn, nm, s);
	}
	s.pop_back();
	visit[n][m] = 0;
}

int find(string& s, int n, int idx)
{
	if (idx == s.length()) 
	{
		if (trie[n].f == 0) return 0;
		int tmp = trie[n].f;
		trie[n].f = b;
		return tmp;
	}
	if (!trie[n].next[s[idx] - 'A']) { return 0; }
	return find(s, trie[n].next[s[idx] - 'A'], idx + 1);
}

void insert(string& s, int n, int idx)
{
	if (idx == s.length()) { trie[n].f = 100; return; }
	if (!trie[n].next[s[idx] - 'A'])
	{
		trie[n].next[s[idx] - 'A'] = trie.size();
		trie.emplace_back(Trie());
	}
	insert(s, trie[n].next[s[idx] - 'A'], idx + 1);
}