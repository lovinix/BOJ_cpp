#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<string> arr[30], vt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> K;
		for (int j = 0; j < K; ++j)
		{
			string s;
			cin >> s;
			arr[i].emplace_back(s);
			vt.emplace_back(s);
		}
	}
	sort(vt.begin(), vt.end());
	vt.erase(unique(vt.begin(), vt.end()), vt.end());
	for (int i = 0; i < vt.size(); ++i)
	{
		for (int j = i + 1; j < vt.size(); ++j)
		{
			int c1 = 0, c2 = 0, c3 = 0;
			for (int k = 0; k < N; ++k)
			{
				int f1 = 0, f2 = 0;
				for (auto& s : arr[k])
				{
					if (s == vt[i]) f1=1;
					if (s == vt[j]) f2=1;
				}
				if (f1 && f2) ++c3;
				else if (f1) ++c1;
				else if (f2) ++c2;
			}
			if (c1 && c2 && c3) { cout << "no"; return 0; }
		}
	}
	cout << "yes";
}