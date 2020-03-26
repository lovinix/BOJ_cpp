#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

int N, dn[] = { -1,1,0,0 }, dm[] = { 0,0,-1,1 }, vst[60][60];
string A[60];
priority_queue<tu, vector<tu>, greater<tu>> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	pq.emplace(0, 0, 0);
	while (!pq.empty())
	{
		auto [d, n, m] = pq.top();
		if (n == N - 1 && m == N - 1) { cout << d; return 0; }
		pq.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nn = n + dn[i], nm = m + dm[i];
			if (nn < 0 || nm < 0 || nn >= N || nm >= N) continue;
			if (vst[nn][nm]) continue;
			pq.emplace(d + !(A[nn][nm] - '0'), nn, nm);
			vst[nn][nm] = 1;
		}
	}
}