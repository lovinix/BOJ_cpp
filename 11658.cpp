#include <bits/stdc++.h>
using namespace std;

int N, M, tree[1100][1100], arr[1100][1100];

void u(int n, int m, int v);
int q(int n, int m);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
		{
			cin >> arr[i][j];
			u(i, j, arr[i][j]);
		}
	}
	while(M--)
	{
		int w;
		cin >> w;
		if(w==0)
		{
			int x, y, c;
			cin >> x >> y >> c;
			u(x, y, c - arr[x][y]);
			arr[x][y] = c;
		}
		else
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << q(x2, y2) - q(x2, y1 - 1) - q(x1 - 1, y2) + q(x1 - 1, y1 - 1) << "\n";
		}
	}
}

void u(int n,int m, int v)
{
	while(n<=N)
	{
		int t = m;
		while(t<=N)
		{
			tree[n][t] += v;
			t += t & -t;
		}
		n += n & -n;
	}
}

int q(int n, int m)
{
	int ret = 0;
	while(n)
	{
		int t = m;
		while(t)
		{
			ret += tree[n][t];
			t -= t & -t;
		}
		n -= n & -n;
	}
	return ret;
}
