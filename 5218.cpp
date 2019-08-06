#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	while(N--)
	{
		string s, t;
		cin >> s >> t;
		cout << "Distances:";
		for(int i=0;i<s.length();++i)
		{
			cout << " " << (t[i] >= s[i] ? t[i] - s[i] : t[i] + 26 - s[i]);
		}
		cout << "\n";
	}
}
