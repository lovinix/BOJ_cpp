#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, cnt[1010][200], dist;
string str = "ACGT", ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		for(int j=0;j<M;++j)
			cnt[j][s[j]]++;
	}
	for (int i = 0; i < M; ++i)
	{
		int mx = -1;
		for (auto& c : str)
			mx = max(cnt[i][c], mx);
		for (auto& c : str)
		{
			if (mx == cnt[i][c])
			{
				ans += c;
				break;
			}
		}
		for (auto& c : str)
		{
			if (mx != cnt[i][c]) dist += cnt[i][c];
			else { mx = 0; }
		}
	}
	cout << ans << "\n" << dist;
}