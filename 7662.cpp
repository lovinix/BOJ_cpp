#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, K;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> K;
		m.clear();
		while (K--)
		{
			char c; int v;
			cin >> c >> v;
			if (c == 'I') m[v]++;
			else
			{
				if (v == 1 && m.size()) 
				{ 
					auto& mx = *m.rbegin();
					if (mx.second == 1) m.erase(mx.first);
					else mx.second--;
				}
				else if (v == -1 && m.size())
				{
					auto& mn = *m.begin();
					if (mn.second == 1) m.erase(mn.first);
					else mn.second--;
				}
			}
		}
		if (!m.size()) cout << "EMPTY\n";
		else cout << m.rbegin()->first << " " << m.begin()->first << "\n";
	}
}