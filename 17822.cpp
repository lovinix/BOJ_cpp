#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int NaN = -2000;
int N, M, T, x, d, k;

struct Plate
{
	int i = 0, A[50]{ 0, };
	int& operator [](int idx) { return A[(idx + i) % M]; }
};

Plate arr[50];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	while (T--)
	{
		cin >> x >> d >> k;
		for (int i = x - 1; i < N; i += x)
			arr[i].i = (arr[i].i + (d > 0 ? 1 : -1)* k + 100 * M) % M;
		int fl = 0, cnt = 0;
		double avg = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (arr[i][j] == NaN) continue;
				++cnt;
				if (i != N - 1 && abs(arr[i][j]) == abs(arr[i + 1][j])) 
				{
					arr[i][j] = -abs(arr[i][j]);
					arr[i + 1][j] = -abs(arr[i + 1][j]);
				}
				if (abs(arr[i][j]) == abs(arr[i][j + 1])) 
				{
					arr[i][j] = -abs(arr[i][j]);
					arr[i][j + 1] = -abs(arr[i][j + 1]);
				}
				if (arr[i][j] < 0) 
				{
					if (j > 0) arr[i][j] = NaN;
					fl = 1;
				}
				else avg += arr[i][j];
			}
			if (arr[i][0] < 0) arr[i][0] = NaN;
		}
		if (fl == 0 && cnt > 0)
		{
			avg /= cnt;
			for (auto& p : arr)
			{
				for_each(p.A, p.A + M, [&](int& v) {
					if (v > 0 && v < avg) ++v;
					else if (v > avg) --v;
					});
			}
		}
	}
	int ans = 0;
	for (auto& p : arr)
		for (auto& v : p.A)
			if (v > 0) ans += v;
	cout << ans;
}