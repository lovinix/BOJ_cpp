#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
string start = "Baba";
set<string> ans;
map<string, vector<string>> m;

void recv(string& s);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--)
	{
		string from, tmp, to;
		cin >> from >> tmp >> to;
		m[from].emplace_back(to);
	}
	recv(start);
	ans.erase(start);
	for (auto& s : ans)
		cout << s << "\n";
}

void recv(string& s)
{
	ans.emplace(s);
	for (auto& v : m[s])
	{
		if (!ans.count(v)) recv(v);
	}
}