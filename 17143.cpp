#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Shark
{
	int r, c, s, d, z, f;
	bool operator<(Shark& s)
	{
		return z < s.z;
	}
};

int R, C, M, ans, arr[110][110], dn[] = { -1,1,0,0 }, dm[] = { 0,0,1,-1 };
Shark shark[10'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> R >> C >> M;
	for (int i = 1; i <= M; ++i)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r--, c--, d--;
		arr[r][c] = i;
		shark[i] = { r,c,s,d,z,1 };
	}
	for (int j = 0; j < C; ++j)
	{
		for (int i = 0; i < R; ++i)
		{
			if (arr[i][j]) 
			{ 
				ans += shark[arr[i][j]].z; 
				shark[arr[i][j]].f = 0; 
				break;
			}
		}
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				arr[i][j] = 0;
		for (int i = 1; i <= M; ++i)
		{
			auto& sh = shark[i];
			if (sh.f == 0) continue;
			int nn = sh.r + ((sh.s * dn[sh.d])%(2*(R-1))), nm = sh.c + ((sh.s * dm[sh.d])%(2*(C-1)));
			for (int tmp = 0; tmp < 2; ++tmp)
			{
				if (nn < 0) { nn = abs(nn); sh.d = 1; }
				if (nn >= R) { nn = R - (nn - R + 2); sh.d = 0; }
				if (nm < 0) { nm = abs(nm); sh.d = 2; }
				if (nm >= C) { nm = C - (nm - C + 2); sh.d = 3; }
			}
			sh.r = nn; sh.c = nm;
			if (arr[nn][nm])
			{
				auto& sh2 = shark[arr[nn][nm]];
				if (sh < sh2) { sh.f = 0; }
				else { sh2.f = 0; arr[nn][nm] = i; }
			}
			else arr[nn][nm] = i;
		}
	}
	cout << ans;
}