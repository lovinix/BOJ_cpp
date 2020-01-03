#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
set<string> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s, t;
		cin >> s >> t;
		if (t == "enter") st.emplace(s);
		else st.erase(s);
	}
	for (auto it = st.rbegin(); it != st.rend(); it++)
		cout << *it << "\n";
}