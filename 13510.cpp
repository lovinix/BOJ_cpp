#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<int> adj[MAX];
int tree[4 * MAX];
int root, node_num, num[MAX], idx[MAX], hld[MAX], W[MAX], depth[MAX], parent[MAX];
int U[MAX], V[MAX], Wi[MAX];
int N, Q;

void Supdate(int node, int s, int e, int i, int v);
int Squery(int node, int s, int e, int l, int r);
void dfs(int c);
void dfs2(int c);
void init_HLD(int N, int r);
int LCA(int a, int b);
void update(int n, int v);
int query(int a, int b);
int query_topdown(int a, int b);
int query(int a, int b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		U[i] = u;
		V[i] = v;
		Wi[i] = w;
	}
	init_HLD(N,1);
	cin >> Q;
	while (Q--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			Wi[b] = c;
			Supdate(1, 1, N, max(num[U[b]], num[V[b]]), c);
		}
		else
		{
			cout << query(b, c) << "\n";
		}
	}

}

void Supdate(int node, int s, int e, int i, int v)
{
	if (s > i || e < i) return;
	if (s == e)
	{
		tree[node] = v; return;
	}
	int m = (s + e) / 2;
	Supdate(2 * node, s, m, i, v);
	Supdate(2 * node + 1, m + 1, e, i, v);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int Squery(int node, int s, int e, int l, int r)
{
	if (s > r || e < l) return 0;
	if (l<=s && e<=r) return tree[node];
	int m = (s + e) / 2;
	return max(Squery(node * 2, s, m, l, r), Squery(node * 2 + 1, m + 1, e, l, r));
}

void dfs(int c)
{
	W[c] = 1;
	for (auto& n : adj[c])
	{
		if (W[n] == 0)
		{
			parent[n] = c;
			depth[n] = depth[c] + 1;
			dfs(n);
			W[c] += W[n];
		}
	}
}

void dfs2(int c)
{
	int cc = -1;
	num[c] = ++node_num;
	idx[num[c]] = c;
	for (auto& n : adj[c])
	{
		if (parent[n] == c && (cc == -1 || W[cc] < W[n]))
			cc = n;
	}
	if (cc != -1)
	{
		hld[cc] = hld[c];
		dfs2(cc);
	}
	for (auto& n : adj[c])
	{
		if (parent[n] == c && n != cc)
		{
			hld[n] = n;
			dfs2(n);
		}
	}
}

void init_HLD(int N, int r)
{
	root = r; parent[r] = r; depth[r] = hld[r] = node_num = 0;
	memset(W, 0, sizeof(W));
	dfs(r);
	dfs2(r);
	for (int i = 1; i < N; ++i)
	{
		if (parent[U[i]] == V[i])
			update(U[i], Wi[i]);
		else
			update(V[i], Wi[i]);
	}
}

int LCA(int a, int b)
{
	while (hld[a] != hld[b])
	{
		if (depth[hld[a]] > depth[hld[b]])
			a = parent[hld[a]];
		else
			b = parent[hld[b]];
	}
	return depth[a] < depth[b] ? a : b;
}

void update(int n, int v)
{
	Supdate(1, 1, node_num, num[n], v);
}

/*
int query(int a, int b)
{
	int ret = 0;
	while (hld[a] != hld[b])
	{
		if (depth[hld[a]] > depth[hld[b]])
		{
			ret = max(ret,Squery(1, 1, node_num, num[hld[a]], num[a]));
		}
		else
		{
			ret = max(ret, Squery(1,1,node_num,num[hld[b]], num[b]));
		}
	}
	if (depth[a] > depth[b]) swap(a, b);
	return max(ret, Squery(1, 1, node_num, num[a], num[b]));
}
*/

int query_topdown(int a, int b)
{
	int ret = 0;
	while (hld[a] != hld[b])
	{
		ret = max(ret, Squery(1, 1, node_num, num[hld[b]], num[b]));
		b = parent[hld[b]];
	}
	return max(ret, Squery(1, 1, node_num, num[a]+1, num[b]));
}

int query(int a, int b)
{
	int lca = LCA(a, b);
	return max({ query_topdown(lca, a), query_topdown(lca, b) });
}