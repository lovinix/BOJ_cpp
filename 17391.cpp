#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

auto cmp = [](tu& t1, tu& t2) {return get<2>(t1) > get<2>(t2); };
int N, M, arr[301][301], visit[301][301], dn[] = { 1,0 }, dm[] = { 0,1 };
priority_queue<tu, vector<tu>, decltype(cmp)> pq(cmp);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i=0;i<N;++i)
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	memset(visit, 0x7f, sizeof visit);
	pq.emplace(0, 0, 0);
	visit[0][0] = 1;
	while(!pq.empty())
	{
		auto [n, m, d] = pq.top();
		pq.pop();
		for(int i=0;i<2;++i)
		{
			for (int z = 1; z <= arr[n][m]; ++z)
			{
				int nn = n + z * dn[i], nm = m + z * dm[i];
				if (nn >= N) nn = N - 1;
				if (nm >= M) nm = M - 1;
				if (visit[nn][nm] <= d + 1) continue;
				visit[nn][nm] = d + 1;
				pq.emplace(nn, nm, d + 1);
			}
		}
	}
	cout << visit[N - 1][M - 1];
}
