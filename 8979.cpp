#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct st
{
	int n, g, s, b;
	bool operator<(st& a)
	{
		return g == a.g ? s == a.s ? b > a.b:s > a.s:g > a.g;
	}
	bool operator==(st& a)
	{
		return g == a.g && s == a.s && b == a.b;
	}
};

int N, K;
st arr[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int n, g, s, b;
		cin >> n >> g >> s >> b;
		arr[i] = { n,g,s,b };
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; ++i)
	{
		if (arr[i].n != K) continue;
		int j = i;
		while (j >= 0 && arr[j] == arr[i]) j--;
		cout << j + 2;
		return 0;
	}
}