#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

}

long long sum(vector<int> &a)
{
	long long ans = 0;
	for (auto& i : a)
		ans += i;
	return ans;
}