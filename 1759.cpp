#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<char> v, st = { 'a','e','i','o','u' };
bitset<20> bset;

void recv(int idx, int cnt);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; ++i)
	{
		char c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	recv(0, 0);

}

void recv(int idx, int cnt)
{
	if (idx == C && cnt < L) return;
	if (cnt == L)
	{
		int a = 0;
		for (int i = 0; i < C; ++i)
		{
			if (bset[i])
			{
				for (auto c : st)
				{
					if (c == v[i]) a++;
				}
			}
		}
		if (a == 0 || a > L - 2) return;
		for (int i = 0; i < C; ++i)
		{
			if (bset[i]) cout << v[i];
		}
		cout << "\n";
		return;
	}
	bset[idx] = true;
	recv(idx + 1, cnt + 1);
	bset[idx] = false;
	recv(idx + 1, cnt);
}