#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, tmp;
char buf[50'000'000];
lli ans;

int main()
{
	fread(buf, 1, sizeof buf, stdin);
	int i = 0;
	while(buf[i]!='\n')
		N = N*10 + buf[i++] - '0';
	printf("%d\n", N);
	++i;
	while(N--)
	{
		tmp = 0;
		while (buf[i]!='\n')
			tmp = tmp * 10 + buf[i++] - '0';
		ans += tmp;
		++i;
	}
	printf("%lld\n",ans);
}
