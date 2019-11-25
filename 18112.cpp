#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using psi = pair<string, int>;

string s,t;
queue<psi> q;
map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s >> t;
	reverse(&s[0], &s[s.length()]);
	reverse(&t[0], &t[t.length()]);
	m[s] = 1;
	q.emplace(s, 0);
	while (!q.empty())
	{
		auto [cur, d] = q.front();
		if (cur == t) { cout << d; return 0; }
		q.pop();
		for (int i = 0; i < cur.length() - 1; ++i)
		{
			string next = cur;
			next[i] = next[i] == '1' ? '0' : '1';
			if (m[next]) continue;
			m[next] = 1;
			q.emplace(next, d + 1);
		}
		string next = cur;
		for (int i = 0; i < next.length(); ++i)
		{
			if (next[i] == '0') { next[i] = '1'; break; }
			next[i] = '0';
			if (i == next.length() - 1) { next += "1"; break; }
		}
		if (m[next] == 0) { m[next] = 1; q.emplace(next, d + 1); }
		next = cur;
		for (int i = 0; i < cur.length(); ++i)
			if (next[i] == '1') goto cont;
		continue;
	cont:
		for (int i = 0; i < next.length(); ++i)
		{
			if (next[i] == '0') { next[i] = '1'; continue; }
			else if (next[i] == '1') { next[i] = '0'; break; }
			break;
		}
		while (next.size() > 1 && next.back() == '0') next.pop_back();
		if (m[next] == 0) { m[next] = 1; q.emplace(next, d + 1); }
	}
}