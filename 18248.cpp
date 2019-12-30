#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[1010][110], cnt[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
			if (arr[i][j]) cnt[i]++;
		}
	}
	vector<int> vt;
	for (int i = 0; i < N; ++i) vt.emplace_back(i);
	stable_sort(vt.begin(), vt.end(), [&](int a, int b) {return cnt[a] > cnt[b]; });
	for (int j = 0; j < M; ++j)
	{
		vector<int> tmp;
		for (int i = 0; i < N; ++i)
			if (arr[i][j]) tmp.emplace_back(i);
		stable_sort(tmp.begin(), tmp.end(), [&](int a, int b) {return cnt[a] > cnt[b]; });
		for(int i=0;i<tmp.size();++i)
			if (tmp[i] != vt[i]) { cout << "NO"; return 0; }
	}
	cout << "YES";
}