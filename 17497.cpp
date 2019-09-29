#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli N;
string str[] = { "[+]","[-]","[*]","[/]" };
vector<string> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	N *= 2;
	int h, f = 0;
	for (int i = 60; i > 0; --i) 
		if (N & 1LL << i) { ans.emplace_back(str[0]); ans.emplace_back(str[2]); f = 1; }
		else if (f) { ans.emplace_back(str[2]); }
	ans[ans.size() - 1] = str[3];
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";	
}