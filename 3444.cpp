#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define node_num 100'010
using namespace std;
using pii = pair<int, int>;

class Splaytree
{
public:
	struct Node
	{
		bool f;
		int l, r, p, v, cnt;
		Node(int _v = 0)
		{
			l = r = p = -1;
			v = _v;
			cnt = 1;
			f = 0;
		}
	};
	int root;
	Node tree[node_num];
	void rotate(int x)
	{
		int p = tree[x].p;
		int b;
		propagate(p);
		propagate(x);
		if (x == tree[p].l)
		{
			tree[p].l = b = tree[x].r;
			tree[x].r = p;
		}
		else
		{
			tree[p].r = b = tree[x].l;
			tree[x].l = p;
		}
		tree[x].p = tree[p].p;
		tree[p].p = x;
		if (b != -1) tree[b].p = p;
		if (tree[x].p == -1) root = x;
		else if (p == tree[tree[x].p].l) tree[tree[x].p].l = x;
		else tree[tree[x].p].r = x;
		update(p);
		update(x);
	}
	void toggle(int x)
	{
		if (x == -1) return;
		tree[x].f ^= 1;
	}
	void propagate(int x)
	{
		if (!tree[x].f) return;
		swap(tree[x].l, tree[x].r);
		toggle(x);
		toggle(tree[x].l);
		toggle(tree[x].r);
	}
	void flip(int l, int r)
	{
		int x = makeseg(l, r);
		toggle(x);
	}
	void merge(int p, int x)
	{
		if (x == -1) return;
		tree[p].cnt += tree[x].cnt;
	}
	void update(int x)
	{
		tree[x].cnt = 1;
		merge(x, tree[x].l);
		merge(x, tree[x].r);
	}
	void splay(int x, int tp = -1)
	{
		while (tree[x].p != tp)
		{
			int p = tree[x].p;
			int g = tree[p].p;
			if (g != tp)
			{
				if ((tree[p].l == x) == (tree[g].l == p)) rotate(p);
				else rotate(x);
			}
			rotate(x);
		}
		if (tp == -1) root = x;
	}
	int makeseg(int l, int r)
	{
		kth(l - 1);
		int x = root;
		kth(r + 1);
		splay(x, root);
		return tree[tree[root].l].r;
	}
	Splaytree() : root(-1) {}
	void init(int n, pii arr[])
	{
		tree[root = 0] = Node(-1);
		for (int i = 1; i <= n + 1; ++i)
		{
			tree[i - 1].r = i;
			tree[i] = Node(i > n ? -1 : arr[i].first);
			tree[i].p = i - 1;
		}
	}
	int kth(int k)
	{
		int t = root;
		while (1)
		{
			propagate(t);
			int lcnt = tree[t].l == -1 ? 0 : tree[tree[t].l].cnt;
			if (lcnt == k) break;
			else if (lcnt < k)
			{
				k -= lcnt + 1;
				t = tree[t].r;
			}
			else t = tree[t].l;
		}
		splay(t);
		return tree[t].v;
	}
	void q(int x, int l)
	{
		splay(x);
		int r = tree[tree[x].l].cnt;
		cout << r << " ";
		flip(l, r);
	}
};


int N;
pii arr[100'010];
Splaytree st;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (cin >> N)
	{
		if (N == 0) return 0;
		for (int i = 1; i <= N; ++i)
		{
			cin >> arr[i].first;
			arr[i].second = i;
		}
		st.init(N, arr);
		sort(arr + 1, arr + N + 1);
		for (int i = 1; i <= N; ++i)
		{
			st.q(arr[i].second, i);
		}
		cout << "\n";
	}
}