#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

int N, M, Q, fl[100'001];
lli p[100'001], ans;
vector<int> qu;
pii arr[100'001];

int f(int u);
void m(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	memset(p, -1, sizeof p);
	qu.reserve(Q);
	for(int i=0;i<M;++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	for(int i=0;i<Q;++i)
	{
		int t;
		cin >> t;
		qu.emplace_back(t-1);
		fl[t - 1] = 1;
	}
	for(int i=0;i<M;++i)
	{
		if (!fl[i]) m(arr[i].first, arr[i].second);
	}
	for(int i=qu.size()-1;i>=0;--i)
	{
		int u = arr[qu[i]].first, v = arr[qu[i]].second;
		if (f(u) == f(v))  continue; 
		ans += (-1LL * p[f(u)]) * (-1LL * p[f(v)]);
		m(u, v);
	}
	cout << ans;
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v)
{
	u = f(u); v = f(v);
	if (u == v) return;
	p[u] += p[v];
	p[v] = u;
}