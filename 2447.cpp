#include <bits/stdc++.h>
using namespace std;

int n;
char arr[7000][7000];

void recv(int r1, int c1, int r2, int c2);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	recv(0, 0, n, n);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cout << (arr[i][j] == '*' ? '*' : ' ');
		}
		cout << "\n";
	}
}

void recv(int r1, int c1, int r2, int c2)
{
	if(r2-r1==3 && c2-c1==3)
	{
		int cnt = 0;
		for(int i=r1;i<r2;++i)
		{
			for(int j=c1;j<c2;++j)
			{
				if (cnt != 4) arr[i][j] = '*';
				else arr[i][j] = ' ';
				++cnt;
			}
		}
		return;
	}
	int dif = (r2 - r1) / 3;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			if (i == 1 && j == 1) continue;
			recv(r1 + i * dif, c1 + j * dif, r1 + (i + 1) * dif, c1 + (j + 1) * dif);
		}
	}
}