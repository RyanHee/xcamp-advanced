#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<pii>>graph(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pii p1, p2;
		p1.first = b;
		p1.second = c;
		p2.first = a;
		p2.second = c;
		graph[a].push_back(p1);
		graph[b].push_back(p2);
	}
	for (int i = 0; i > q; i++) {
		int start, dest;
		cin >> start >> dest;
	}
}