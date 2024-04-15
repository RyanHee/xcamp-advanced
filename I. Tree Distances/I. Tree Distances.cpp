#include <bits/stdc++.h>

using namespace std;

vector<int>parent;
vector<int>depth_vector;
unordered_map<int, int> root_c_depth_max;

int opp(int p)
{
	for (auto it:root_c_depth_max)
	{
		if (p!=it.first)
		{
			return it.first;
		}
	}
}

void dfs(vector<vector<int>>tree, int curr, int p, int depth)
{
	parent[curr] = p;
	depth_vector[curr] = depth;
	root_c_depth_max[p] = max(root_c_depth_max[p], depth);
	for (int c:tree[curr])
	{
		dfs(tree, c, p, depth + 1);
	}
}

void update(vector<vector<int>>tree, int root)
{
	parent.resize(tree.size());
	depth_vector.resize(tree.size());
	for (int c:tree[root])
	{
		dfs(tree, c, c, 1);
	}
}


int main()
{
	int n;
	cin >> n;
	vector<vector<int>>tree(n);
	
	int root;
	vector<bool>find_root(n);
	for (int i=0;i<n-1;i++)
	{
		int a, b;
		cin >> a >> b;
		find_root[b-1] = true;
		tree[a-1].push_back(b-1);
	}

	for (int i=0;i<n;i++)
	{
		if (!find_root[i])
		{
			root = i;
			break;
		}
	}
	//cout << root << endl;
	update(tree, root);

	for (int i=0;i<n;i++)
	{
		if (i==root)
		{
			//root
			int result;
			for (int c:tree[i])
			{
				result = max(root_c_depth_max[c], result);
			}
			cout << result << " ";
		}
		else
		{
			int result = max(root_c_depth_max[parent[i]] - depth_vector[i], depth_vector[i] + root_c_depth_max[opp(parent[i])]);
			cout << result << " ";
		}
	}
	cout << endl;

	



}