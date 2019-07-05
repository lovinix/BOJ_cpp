#include <bits/stdc++.h>
#define S 0
#define E 400000
#define mov 200000
#define lli long long int
#define MOD 1000000007
using namespace std;

int N;
lli ans;
lli tree[4 * 400010];
vector<pair<int, int>> star;
vector<int> tmp;

void update(int n, int s, int e, int x);
lli query(int n, int s, int e, int l, int r);
bool cmp(pair<int, int>& a, pair<int, int>& b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		star.push_back({ x + mov,y });
	}
	sort(star.begin(), star.end(), cmp);
	int cur = star[0].second;
	for (auto& st : star)
	{
		int x = st.first;
		int y = st.second;
		if (y == cur)
			tmp.push_back(x);
		else
		{
			for (auto& v : tmp)
			{
				update(1, S, E, v);
			}
			cur = y;
			tmp.clear();
			tmp.push_back(x);
		}
		ans += query(1, S, E, S, x - 1) * query(1, S, E, x + 1, E);
		ans %= MOD;
	}
	cout << ans;
}

void update(int n, int s, int e, int x)
{
	if (s > x || e < x) return;
	tree[n]++;
	if (s == e) return;
	int m = (s + e) / 2;
	update(n * 2, s, m, x);
	update(n * 2 + 1, m + 1, e, x);
}

lli query(int n, int s, int e, int l, int r)
{
	if (e<l || s>r) return 0;
	if (l <= s && e <= r)
	{
		return tree[n];
	}
	int m = (s + e) / 2;
	return query(n * 2, s, m, l, r) + query(n * 2 + 1, m + 1, e, l, r);
}

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.second > b.second;
}