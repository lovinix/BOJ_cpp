#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, sum;
pii arr[3];
string s[] = { "Soongsil", "Korea","Hanyang" };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<3;++i)
	{
		cin >> arr[i].first;
		sum += arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + 3);
	if (sum >= 100) cout << "OK";
	else cout << s[arr[0].second];
}
