#include <bits/stdc++.h>
using namespace std;

int N;
char ans[500];
string ps;
vector<pair<string, int>> arr[101];
vector<string> cmp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i=0;i<2*N-2;++i)
	{
		string s;
		cin >> s;
		arr[s.length()].emplace_back( s, i );
		if (s.length() == N - 1)
			cmp.push_back(s);
	}
	string s, p;
	if (cmp[0].substr(1) == cmp[1].substr(0, cmp[1].length() - 1))
		s = cmp[1], p = cmp[0];
	else
		s = cmp[0], p = cmp[1];
	ps = p + s[s.length() - 1];
	for (int i = 1; i < N; ++i)
	{
		if (arr[i][0].first == p.substr(0, arr[i][0].first.length()))
			ans[arr[i][0].second] = 'P', ans[arr[i][1].second] = 'S';
		else if (arr[i][0].first == s.substr(s.length()-arr[i][0].first.length()))
			ans[arr[i][0].second] = 'S', ans[arr[i][1].second] = 'P';
		else
		{
			swap(p, s);
			ps = p + s[s.length() - 1];
			i = 0;
		}
	}
	cout << ps << "\n";
	for (int i = 0; i < 2 * N - 2; ++i)
		cout << ans[i];
}
