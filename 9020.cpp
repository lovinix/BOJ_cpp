#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

bool p[MAX];
int T, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(p, 1, sizeof p);
	for(int i=2;i*i<MAX;++i)
	{
		if (!p[i]) continue;
		for(int j=i+i;j<MAX;j+=i)
		{
			p[j] = 0;
		}
	}
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=n/2;i>0;--i)
		{
			if(p[i]&&p[n-i])
			{
				cout << i << " " << n - i << "\n";
				break;
			}
		}
	}
}
