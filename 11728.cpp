#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, A[1'000'010], B[1'000'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < M; ++i)
		cin >> B[i];
	int i = 0, j = 0;
	while (i < N && j < M)
	{
		if (A[i] < B[j]) cout << A[i++] << " ";
		else cout << B[j++] << " ";
	}
	while (i < N) cout << A[i++] << " ";
	while (j < M) cout << B[j++] << " ";
}