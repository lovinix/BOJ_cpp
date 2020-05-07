#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Query { int s, e, i; };

int N, M, sqrtN, A[100'010], fw[100'010];
Query q[100'010];
lli cur, ans[100'010];
vector<int> vt;

void fu(int i, int v)
{
	++i;
	while (i <= vt.size())
	{
		fw[i] += v;
		i += i & -i;
	}
}

int fq(int i)
{
	++i;
	int ret = 0;
	while (i)
	{
		ret += fw[i];
		i -= i & -i;
	}
	return ret;
}

void add(int i, int t)
{
	cur += t ? fq(vt.size() - 1) - fq(A[i]) : fq(A[i] - 1);
	fu(A[i], 1);
}

void rm(int i, int t)
{
	cur -= t ? fq(vt.size() - 1) - fq(A[i]) : fq(A[i] - 1);
	fu(A[i], -1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	sqrtN = sqrt(N);
	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
		vt.emplace_back(A[i]);
	}
	sort(vt.begin(), vt.end());
	vt.erase(unique(vt.begin(), vt.end()), vt.end());
	for (int i = 1; i <= N; ++i)
		A[i] = lower_bound(vt.begin(), vt.end(), A[i]) - vt.begin();
	for (int i = 0; i < M; ++i)
	{
		cin >> q[i].s >> q[i].e;
		q[i].i = i;
	}
	sort(q, q + M, [&](Query& p1, Query& p2) {
		return p1.s / sqrtN == p2.s / sqrtN ? 
			p1.e < p2.e : 
			p1.s / sqrtN < p2.s / sqrtN;
		});
	int l = 1, r = 1;
	for (int i = 0; i < M; ++i)
	{
		auto& [s, e, idx] = q[i];
		while (l < s) rm(l++, 0);
		while (l > s) add(--l, 0);
		while (r <= e) add(r++, 1);
		while (r > e + 1) rm(--r, 1);
		ans[idx] = cur;
	}
	for (int i = 0; i < M; ++i)
		cout << ans[i] << "\n";
}