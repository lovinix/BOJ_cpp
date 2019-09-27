#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int bias = 1'000'000;
int N, cnt[2'000'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int tmp; cin >> tmp;
		cnt[tmp + bias]++;
	}
	for(int i=0;i<=2*bias;++i)
		while (cnt[i]--)
			cout << i-bias << "\n";
}