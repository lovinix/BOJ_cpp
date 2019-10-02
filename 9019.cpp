#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pis = pair<int, string>;

const int MOD = 1e4;
int T, A, B, v[10010];
queue<pis> q;

inline int d(int x);
inline int s(int x);
inline int l(int x);
inline int r(int x);

int (*farr[4])(int) = { d,s,l,r };
string str = "DSLR";

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		q.emplace(A, "");
		memset(v, 0, sizeof v);
		while (!q.empty())
		{
			auto [n, s] = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int next = farr[i](n);
				if (v[next]) continue;
				if (next == B)
				{
					cout << s << str[i] << "\n";
					while (!q.empty()) q.pop();
					goto skip;
				}
				v[next] = 1;
				q.emplace(next, s + str[i]);
			}
		}
	skip:;
	}
}

inline int d(int x)
{
	return (x * 2) % MOD;
}

inline int s(int x)
{
	return (x - 1 + MOD) % MOD;
}

inline int l(int x)
{
	int tmp = x / 1000;
	return (x * 10 + tmp) % MOD;
}

inline int r(int x)
{
	int tmp = x % 10;
	return (x / 10 + 1000 * tmp);
}