#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	if (K == 1 || K == N - 1)
	{
		if (N == 2) 
		{ 
			cout << "YES\n"; 
			for (int i = 0; i < 5; ++i) 
				cout << "swap 1 2\n"; 
			return 0; 
		}
		if (N == 3)
		{
			cout << "NO\n"; 
			return 0;
		}
		if (N == 4)
		{
			cout << "YES\n";
			if (K == 3)
				cout << "swap 2 4\n";
			else
				cout << "swap 1 3\n";
			cout << "swap 1 2\n";
			cout << "swap 3 4\n";
			cout << "swap 1 2\n";
			cout << "swap 1 2\n";
			return 0;
		}
		cout << "YES\n";
		cout << "reverse 1 " << N << "\n";
		if (K == N - 1)
		{
			cout << "swap 2 " << N << "\n";
			cout << "reverse 3 " << N - 1 << "\n";
			cout << "reverse 3 " << N - 1 << "\n";
			cout << "reverse 3 " << N - 1 << "\n";
		}
		else
		{
			cout << "swap 1 " << N - 1 << "\n";
			cout << "reverse 2 " << N - 2 << "\n";
			cout << "reverse 2 " << N - 2 << "\n";
			cout << "reverse 2 " << N - 2 << "\n";
		}
		return 0;
	}
	cout << "YES\n";
	cout << "reverse 1 " << N << "\n";
	cout << "reverse 1 " << N - K << "\n";
	cout << "reverse " << N - K + 1 << " " << N << "\n";
	cout << "swap 1 2\n";
	cout << "swap 1 2\n";
}