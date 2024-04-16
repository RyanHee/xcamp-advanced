#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
//#define INF 0x3f3f3f3f 
int n;

void floyd_warshall(int m, int q)
{
	vector<vector<ll>>dist(n + 1, vector<ll>(n + 1, LONG_MAX));
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	

	for (int i=1; i<=n;i++)
	{
		dist[i][i] = 0;
	}
	

	for (int k=1;k<=n;k++)
	{
		for (int i=1; i<=n;i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j]>dist[k][j]+dist[i][k] && dist[k][j]!=LONG_MAX && dist[i][k]!=LONG_MAX)
				{
					dist[i][j] = dist[k][j] + dist[i][k];
				}
			}
		}
	}
	vector<int>result(q);
	for (int i = 0; i < q; i++) {
		int start, dest;
		cin >> start >> dest;
		if (dist[start][dest] == LONG_MAX)
		{
			result[i] = -1;
		}
		else
		{
			result[i] = dist[start][dest];
		}
	}

	for (int i:result)
	{
		cout << i << endl;
	}

}


int main() {
	int m, q;
	cin >> n >> m >> q;
	floyd_warshall(m, q);
}