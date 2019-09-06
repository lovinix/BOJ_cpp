#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 100'010;
int T, N, K, seg[4*MAX][2], arr[MAX];

void init(int n = 1, int s = 0, int e = N - 1);
void u(int i, int v, int n = 1, int s = 0, int e = N - 1);
pii q(int l, int r, int n = 1, int s = 0, int e = N - 1);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		init();
		for (int i = 0; i < N; ++i) arr[i] = i;
		while (K--)
		{
			int Q, A, B;
			cin >> Q >> A >> B;
			if (!Q)
			{
				swap(arr[A], arr[B]);
				u(A, arr[A]);
				u(B, arr[B]);
			}
			else
			{
				auto t = q(A, B);
				if (t.first == B && t.second == A)
					cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}

void init(int n, int s, int e)
{
	if (s == e)
	{
		seg[n][0] = seg[n][1] = s; return;
	}
	int m = s + e >> 1;
	init(n * 2, s, m);
	init(n * 2 + 1, m + 1, e);
	seg[n][0] = max(seg[n * 2][0], seg[n * 2 + 1][0]);
	seg[n][1] = min(seg[n * 2][1], seg[n * 2 + 1][1]);
}

void u(int i, int v, int n, int s, int e)
{
	if (s == e) { seg[n][0] = seg[n][1] = v; return; }
	int m = s + e >> 1;
	if (i <= m)
		u(i, v, n * 2, s, m);
	else
		u(i, v, n * 2 + 1, m + 1, e);
	seg[n][0] = max(seg[n * 2][0], seg[n * 2 + 1][0]);
	seg[n][1] = min(seg[n * 2][1], seg[n * 2 + 1][1]);
}

pii q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return { -1,MAX };
	if (l <= s && e <= r) return { seg[n][0],seg[n][1] };
	int m = s + e >> 1;
	auto ret1 = q(l, r, n * 2, s, m);
	auto ret2 = q(l, r, n * 2 + 1, m + 1, e);
	return { max(ret1.first,ret2.first),min(ret1.second,ret2.second) };
}