#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> tree[4 * 100'001];

void u(int i, int v, int n = 1, int s = 1, int e = N);
vector<int> q(int l, int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (auto& v : tree) v = { 0,0 };
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int t; cin >> t;
		u(i, t);
	}
	cin >> M;
	while (M--)
	{
		int f, i, v, l, r;
		cin >> f;
		if (f == 1)
		{
			cin >> i >> v;
			u(i, v);
		}
		else
		{
			cin >> l >> r;
			auto tmp = q(l, r);
			cout << tmp[0] + tmp[1] << "\n";
		}
	}
}

void u(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	if (s == e) { tree[n][0] = v; return; }
	int m = s + e >> 1;
	u(i, v, n * 2, s, m);
	u(i, v, n * 2 + 1, m + 1, e);
	priority_queue<int> pq;
	for (auto& a : tree[n * 2]) pq.push(a);
	for (auto& a : tree[n * 2 + 1]) pq.push(a);
	tree[n][0] = pq.top(); pq.pop();
	tree[n][1] = pq.top(); pq.pop();
}

vector<int> q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return {};
	if (l <= s && e <= r) return tree[n];
	int m = s + e >> 1;
	priority_queue<int> pq;
	for (auto& a : q(l, r, n * 2, s, m)) pq.push(a);
	for (auto& a : q(l, r, n * 2 + 1, m + 1, e)) pq.push(a);
	vector<int> ret;
	ret.push_back(pq.top()); pq.pop();
	ret.push_back(pq.top()); pq.pop();
	while (!pq.empty()) pq.pop();
	return ret;
}