#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 2e18 
int n;

void floyd_warshall(int m, int q)
{
	ll dist[601][601];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		dist[a][b] = min(c, dist[a][b]);
		dist[b][a] = dist[a][b];
	}


	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}


	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k) {
				continue;
			}
			for (int j = 1; j <= n; j++)
			{
				if (j == k) {
					continue;
				}
				else if (dist[i][j] > dist[k][j] + dist[i][k] && dist[k][j] != INF && dist[i][k] != INF)
				{
					dist[i][j] = dist[k][j] + dist[i][k];
					dist[j][i] = dist[i][j];
				}
			}
		}
	}
	vector<ll>result(q);
	for (int i = 0; i < q; i++) {
		int start, dest;
		cin >> start >> dest;
		if (dist[start][dest] == INF)
		{
			result[i] = -1;
		}
		else
		{
			result[i] = dist[start][dest];
		}
	}

	for (ll i : result)
	{
		cout << i << endl;
	}

}


int main() {
	int m, q;
	cin >> n >> m >> q;
	floyd_warshall(m, q);
}