#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int solve(int curr, int end, vector<pii>graph, vector<bool>visited, int presses, int N)
{
	//cout << curr << " " << presses << endl;
	if (curr<0 ||curr>=N)
	{
		return N;
	}
	if (visited[curr])
	{
		return N;
	}
	if (curr==end)
	{
		return presses;
	}
	visited[curr] = true;

	return min(solve(graph[curr].first, end, graph, visited, presses+1, N),
		solve(graph[curr].second, end, graph, visited, presses+1, N));
}

int main()
{
	vector<int>result;
	//cout << __cplusplus << endl;
	
	while (true){
		int n;
		cin >> n;
		if (n==0)
		{
			break;
		}
		int start, end;
		cin >> start >> end;
		vector<pii>graph(n);
		for (int i=0;i<n;i++)
		{
			int x;
			cin >> x;
			graph[i].first = i - x;
			graph[i].second = i + x;
		}
		vector<bool>visited(n);
		/*
		for (pii p:graph)
		{
			cout << p.first << " " << p.second << endl;
		}*/
		int out = solve(start - 1, end - 1, graph, visited, 0, n);
		if (out==n)
		{
			out = -1;
		}
		result.push_back(out);
	}

	for (int i:result)
	{
		cout << i << endl;
	}
	
}