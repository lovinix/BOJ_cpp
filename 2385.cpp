#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
string arr[110], tmp;

bool cmp(string& s1, string& s2)
{
	return s1 + s2 < s2 + s1;
}

bool cmp2(string& s1, string& s2)
{
	return s1 + tmp + s2 < s2 + tmp + s1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N, cmp);
	int idx = 0;
	while (arr[idx][0] == '0') tmp += arr[idx++];
	if (idx == N) { cout << "INVALID"; return 0; }
	int t = min_element(arr + idx, arr + N, cmp2) - arr;
	cout << arr[t];
	for (int i = 0; i < N; ++i)
	{
		if(i!=t) cout << arr[i];
	}
}