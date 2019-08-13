#include <bits/stdc++.h>
using namespace std;

int T, N, A, B;
bool p[1'000'001], visit[1'000'001];
queue<pair<int,int>> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(p, 1, sizeof p);
	p[0] = p[1] = 0;
	for(int i=2;i*i<=1'000'000;++i)
	{
		if (!p[i]) continue;
		for(int j=i+i;j<=1'000'000;j+=i)
		{
			p[j] = 0;
		}
	}
	cin >> T;
	while(T--)
	{
		cin >> N >> A >> B;
		memset(visit, 0, sizeof visit);
		for(int z=A;z<=B;++z)
		{
			if (p[z]) goto st;
		}
		cout << "-1\n";
		continue;
		st:
		while (!q.empty()) q.pop();
		q.push({ N,0 });
		while(!q.empty())
		{
			auto [a, d] = q.front();
			q.pop();
			if(A<=a && a<=B && p[a])
			{
				cout << d << "\n";
				break;
			}
			if (a / 2 != 0 && !visit[a/2]) visit[a/2]=1, q.push({ a / 2,d + 1 });
			if (a / 3 != 0 && !visit[a/3]) visit[a/3]=1, q.push({ a / 3,d + 1 });
			if (a < 1'000'000 && !visit[a+1]) visit[a + 1] = 1, q.push({ a + 1,d + 1 });
			if (a != 0 && !visit[a-1]) visit[a-1] =1, q.push({ a - 1,d + 1 });
		}
	}
}
