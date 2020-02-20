#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, A[10];

void recv(int idx)
{
	if (idx == M) 
	{ 
		for (int i = 0; i < M; ++i)
			cout << A[i] << " ";
		cout << "\n";
		return; 
	}
	for (int i = 1; i <= N; ++i)
	{
		A[idx] = A[idx] % N + 1;
		recv(idx + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	recv(0);
}