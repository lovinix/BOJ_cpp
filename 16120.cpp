#include <bits/stdc++.h>
using namespace std;

string s;
vector<char> stk;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i=0;i<s.length();++i)
	{
		if (s[i] == 'P')
		{
			if (stk.size() >= 3 && stk[stk.size() - 1] == 'A' && stk[stk.size() - 2] == 'P' && stk[stk.size() - 3] == 'P')
			{
				stk.pop_back();
				stk.pop_back();
			}
			else
				stk.push_back('P');
		}
		else
			stk.push_back('A');
	}
	if (stk.size() == 1 && stk[0] == 'P') cout << "PPAP";
	else cout << "NP";
}
