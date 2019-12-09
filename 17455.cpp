#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, s[200'010], vst[200'010], f[200'010], dist[200'010], ans;
string str;
vector<int> adj[200'010];

int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	cin >> str;
	for (int i = 1; i <= N; ++i)
	{
		s[i] = str[i - 1] == 'K' ? 0 : str[i - 1] == 'D' ? 1 : 2;
	}
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		if ((s[u] + 1) % 3 == s[v]) adj[u].emplace_back(v);
		if ((s[v] + 1) % 3 == s[u]) adj[v].emplace_back(u);
	}
	for (int i = 1; i <= N; ++i)
		if (s[i] == 0 && !vst[i]) ans = max(ans, dfs(i));
	if (ans < 3) cout << -1;
	else
		cout << ans - ans % 3;
}

int dfs(int u)
{
	vst[u] = 1;
	int ret = 0;
	for (auto& v : adj[u])
	{
		if (!vst[v]) ret = max(ret, dfs(v));
		else
		{
			if (!f[v]) { cout << -1; exit(0); }
			ret = max(ret, dist[v]);
		}
	}
	f[u] = 1;
	return dist[u] = ret + 1;
}