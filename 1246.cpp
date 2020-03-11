#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

char buf[10'000'010];
int N, M, idx, A[1010];

inline int nextInt()
{
	int ret = 0;
	while (buf[idx] != '\n' && buf[idx] != ' ' && buf[idx] != 0) ret = ret * 10 + buf[idx++] - '0';
	while (buf[idx] == '\n' || buf[idx] == ' ') ++idx;
	return ret;
}

int main()
{
	fread(buf, 1, sizeof buf, stdin);
	N = nextInt(); M = nextInt();
	for (int i = 0; i < M; ++i)
		A[i] = nextInt();
	sort(A, A + M);
	int ans = 0, ansi;
	for (int i = 0; i < M; ++i)
	{
		if (int cur = A[i] * min(N, M - i); ans < cur)
		{
			ans = cur;
			ansi = A[i];
		}
	}
	printf("%d %d", ansi, ans);
}