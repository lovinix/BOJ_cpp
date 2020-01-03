#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int A, B, M, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> A >> B >> M;
	for (int i = M - 1; i >= 0; --i)
	{
		int v; cin >> v;
		t += v * (int)pow(A, i);
	}
	vector<int> vt;
	while (t)
	{
		vt.emplace_back(t % B);
		t /= B;
	}
	for (auto it = vt.rbegin(); it != vt.rend(); ++it)
		cout << *it << " ";
}