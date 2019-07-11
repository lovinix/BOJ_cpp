#include <bits/stdc++.h>
using namespace std;

int N;
char arr[310][310];
int p[310], s[310];
vector<int> scc[310], root;
vector<pair<int, int>> ans;

int find(int u);
void merge(int u, int v);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
			p[i] = i;
			s[i] = 1;
			scc[i].clear();
		}
		root.clear();
		ans.clear();
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if ((arr[i][j] == '1') && (arr[j][i] == '1'))
				{
					merge(i, j);
				}
			}
		}
		for (int i = 0; i < N; ++i)
			scc[find(i)].push_back(i);
		int n = 0;
		for (int i = 0; i < N; ++i)
		{
			if (p[i] == i) root.push_back(i);
		}
		for (int i = 0; i < root.size(); ++i)
		{
			if (s[root[i]] != 1)
			{
				n += s[root[i]];
				for (int j = 0; j < scc[root[i]].size()-1; ++j)
				{
					ans.push_back({ scc[root[i]][j],scc[root[i]][j + 1] });
				}
				ans.push_back({ scc[root[i]][scc[root[i]].size() - 1] , scc[root[i]][0] });
			}
			for (int j = 0; j < root.size(); ++j)
			{
				if (i!=j && arr[root[i]][root[j]] == '1')
				{
					bool flag = true;
					for (int k = 0; k < root.size(); ++k)
					{
						if (k == i || k == j) continue;
						if (arr[root[i]][root[k]] == '1' && arr[root[k]][root[j]] == '1')
						{
							flag = false; break;
						}
					}
					if (flag)
					{
						n++;
						ans.push_back({ root[i],root[j] });
					}
				}
			}
		}
		cout << n << "\n";
		for (auto& v : ans)
		{
			cout << v.first+1 << " " << v.second+1 << "\n";
		}
		cout << "\n";
	}
}

int find(int u)
{
	if (p[u] == u) return u;
	return p[u] = find(p[u]);
}

void merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v) return;
	p[v] = u;
	s[u] += s[v];
}