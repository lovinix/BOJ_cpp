#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

int T, R, C, dn[] = { -1,1,0,0 }, dm[] = { 0,0,-1,1 }, vst[110][110];
string arr[110];
queue<tu> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> R >> C;
		memset(vst, 0, sizeof vst);
		arr[0].clear();
		for (int i = 0; i <= C + 1; ++i)
			arr[0] += '.';
		for (int i = 1; i <= R; ++i)
		{
			string s;
			cin >> s;
			arr[i] = "." + s + ".";
		}
		arr[R + 1].clear();
		for (int i = 0; i <= C + 1; ++i)
			arr[R + 1] += '.';
		R++, C++;
		int st = 1<<27;
		string s;
		cin >> s;
		if (s != "0") { for (auto& c : s) st |= 1 << (c - 'a'); }
		q.emplace(0, 0, st);
		vst[0][0] = st;
		int ans = 0;
		while (!q.empty())
		{
			auto [n, m, st] = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nn = n + dn[i], nm = m + dm[i], nst = st;
				if (nn<0 || nm<0 || nn>R || nm>C) continue;
				if (arr[nn][nm] == '*') continue;
				if (arr[nn][nm] >= 'A' && arr[nn][nm] <= 'Z' && !(st & 1 << (arr[nn][nm] - 'A'))) continue;
				if ((vst[nn][nm]|st)==vst[nn][nm]) continue;
				if (arr[nn][nm] >= 'a' && arr[nn][nm] <= 'z') nst |= 1 << (arr[nn][nm] - 'a');
				if (arr[nn][nm] == '$') { ans++; arr[nn][nm] = '.'; }
				nst |= vst[nn][nm];
				q.emplace(nn, nm, nst);
				vst[nn][nm] |= st;
			}
		}
		cout << ans << "\n";
	}
}
