#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
map<string,int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 111; i <= 999; ++i)
	{
		string str = to_string(i);
		if (str[0] == '0' || str[1] == '0' || str[2] == '0') continue;
		if (str[0] == str[1] || str[1] == str[2] || str[0] == str[2]) continue;
		m[str]++;
	}
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int v, st, b;
		cin >> v >> st >> b;
		string str = to_string(v);
		for (auto& [p,v] : m)
		{
			if (v == 0) continue;
			int z = 0, x = 0;
			for (int j = 0; j < 3; ++j)
			{
				if (str[j] == p[j]) z++;
				for (int k = 0; k < 3; ++k)
				{
					if (k == j) continue;
					if (str[j] == p[k]) x++;
				}
			}
			if (st == z && b == x) continue;
			m[p]--;
		}
	}
	int ans = 0;
	for (auto& [p, v] : m)
		if (v) ++ans;
	cout << ans;
}