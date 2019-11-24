#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

char s[300];
string ans;
deque<string> abbr;

void flushabbr()
{
	if (abbr.empty()) return;
	if (abbr.size() == 1) { ans += abbr[0]; }
	else
	{
		for (auto& t : abbr)
			ans += t[0];
		ans += " (";
		for (auto& t : abbr)
			ans += t;
		char t = ans.back();
		if (t == ' ' || t == '\0')
			ans.pop_back();
		ans += ")";
		if (t == ' ')
			ans += t;
	}
	abbr.clear();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (cin.getline(s, 200))
	{
		int len = strlen(s);
		for (int i = 0; i<len; ++i)
		{
			int flag = 1, j = i;
			string tmp;
			for (; j<len && s[j] != '\0' && s[j] != ' ' && s[j] != '.' && s[j] != ','; ++j)
			{
				tmp += s[j];
			}
			if(s[j]!='\0') tmp += s[j];
			for (int k = 1; k < tmp.length(); ++k)
			{
				if (tmp[k] >= 'A' && tmp[k] <= 'Z') flag = 0;
			}
			if (tmp.length() < 2 || tmp[0] >= 'a' && tmp[0] <= 'z') flag = 0;
			if (tmp.length() == 2 && (tmp[1] == '.' || tmp[1] == ',' || tmp[1] == ' ')) flag = 0;
			stack<char> a;
			while (flag==1 && tmp.size() && (tmp.back() == '.' || tmp.back() == ',' || tmp.back() == '\n'))
			{
				char c = tmp.back(); tmp.pop_back(); a.emplace(c);
			}
			if (a.size() && flag == 1) { abbr.emplace_back(tmp); tmp = ""; flag = 0; }
			if (flag == 1) abbr.emplace_back(tmp);
			else { flushabbr(); if(tmp.size()) ans += tmp; while (a.size()) { ans += a.top(); a.pop(); } }
			i = j;
		}
		flushabbr();
		ans += "\n";
	}
	while (ans.back() == '\n') ans.pop_back();
	cout << ans;
}