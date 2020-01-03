#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int arr[5];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; ++i)
		cin >> arr[i];
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				for (int k = 0; k < 5; ++k)
					cout << arr[k] << " ";
				cout << "\n";
			}
		}
	}
}