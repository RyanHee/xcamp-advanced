#include <bits/stdc++.h>

using namespace std;

#define N 200000

vector<int> tree[N];
int height[N];
int max_dist[N];

void height_dfs(int curr, int p) {
	
	for (auto i : tree[curr]) {
		if (i != p) {
			height_dfs(i, curr);
			height[curr]=max(height[i], height[curr]);
		}
	}
	height[curr]++;
}


void dfs2(int curr, int parent) {
	int max1 = 0;
	int max2 = 0;
	for (auto c : tree[curr]) {
		if (c != parent) {
			if (height[c] >= max1) {
				max2 = max1;
				max1 = height[c];
			}
			else if (height[c] > max2) {
				max2 = height[c];
			}
		}
	}

	for (auto c : tree[curr]) {
		if (c != parent) {
			if (max1 == height[c]) {
				max_dist[c] = 1 + max(max_dist[curr], 1 + max2);
			}
			else {
				max_dist[c] = 1 + max(max_dist[curr], 1 + max1);
			}
			dfs2(c, curr);
		}
	}
}


int main()
{
	int n;
	cin >> n;
	
	
	for (int i=0;i<n-1;i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a - 1].push_back(b - 1);
		tree[b - 1].push_back(a - 1);
	}

	
	height_dfs(0, -1);
	dfs2(0, -1);
	for (int i = 0; i < n; i++) {
		cout << max(max_dist[i], height[i]) - 1 << " ";
	}
	cout << endl;
	

	



}