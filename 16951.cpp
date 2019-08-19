#include <bits/stdc++.h>
using namespace std;

int N, K, arr[1001], ans=123456789;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	for(int i=1;i<=1000;++i)
	{
		int cnt = arr[0] != i;
		for(int j=1;j<N;++j)
			if (arr[j] != i + K * j) ++cnt;
		ans = min(ans, cnt);
	}
	cout << ans;
}
