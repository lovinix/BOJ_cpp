#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;
using tu = tuple<double, int, int>;

int N, p[101];
double ans;
pdd d[101];
priority_queue<tu,vector<tu>,greater<tu>> pq;

inline double dist(pdd& p1, pdd& p2);
int f(int u);
void m(int u, int v, double w);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	memset(p, -1, sizeof p);
	for (int i = 0; i < N; ++i)
	{
		cin >> d[i].first >> d[i].second;
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			double t = dist(d[i], d[j]);
			pq.emplace(t, i, j);
		}
	}
	while (!pq.empty())
	{
		auto [w, u, v] = pq.top();
		m(u, v, w);
		pq.pop();
	}
	cout << ans;
}

inline double dist(pdd& p1, pdd& p2)
{
	return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v, double w)
{
	u = f(u), v = f(v);
	if (u == v) return;
	ans += sqrt(w);
	p[u] += p[v];
	p[v] = u;
}