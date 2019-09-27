#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[1'000'010], tmp[1'000'010];

void mergesort(int l, int r, int arr[]);
void merge(int l, int m, int r, int arr[]);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	mergesort(0, N - 1, arr);
	for (int i = 0; i < N; ++i)
		cout << arr[i] << "\n";
}

void mergesort(int l, int r, int arr[])
{
	if (l < r)
	{
		int m = l + r >> 1;
		mergesort(l, m, arr);
		mergesort(m + 1, r, arr);
		merge(l, m, r, arr);
	}
}

void merge(int l, int m, int r, int arr[])
{
	int a = l, b = m + 1, c = l;
	while (a <= m && b <= r)
	{
		if (arr[a] < arr[b]) tmp[c++] = arr[a++];
		else tmp[c++] = arr[b++];
	}
	while (a <= m) tmp[c++] = arr[a++];
	while (b <= r) tmp[c++] = arr[b++];
	while (l <= r) arr[l] = tmp[l], l++;
}