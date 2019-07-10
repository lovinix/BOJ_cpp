#include <bits/stdc++.h>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;

int N, M;
vector<int> arr[10001];
bool isvisited[10001];
int ans[10001];

int recv(int u);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		arr[v].push_back(u);
	}
	int m = -1;
	for (int i = 1; i <= N; ++i)
	{
		ans[i] = recv(i);
		m = max(m, ans[i]);
		memset(isvisited, 0, sizeof(isvisited));
	}
	for (int i = 1; i <= N; ++i)
	{
		if (ans[i] == m) cout << i << " ";
	}
}

int recv(int u)
{
	if (isvisited[u]) return 0;
	isvisited[u] = true;
	int ret = 1;
	for (auto& v : arr[u])
	{
		ret += recv(v);
	}
	return ret;
}

