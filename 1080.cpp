#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
string a[51], b[51];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < N; ++i) cin >> b[i];
	if (N < 3 || M < 3) for (int i = 0; i < N; ++i) if (a[i] != b[i]) { cout << "-1"; return 0; }
	for(int i=0;i<N-2;++i) for(int j=0;j<M-2;++j)
		if(a[i][j]!=b[i][j])
		{
			for (int k = i; k < i + 3; ++k) for (int l = j; l < j + 3; ++l)
				a[k][l] = a[k][l] == '1' ? '0' : '1';
			++cnt;
		}
	for(int i=0;i<N;++i)
		if (a[i] != b[i]) { cout << "-1"; return 0; }
	cout << cnt;
}
