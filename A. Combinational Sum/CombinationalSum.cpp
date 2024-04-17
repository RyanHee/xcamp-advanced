#include <bits/stdc++.h>

using namespace std;

bool solve(int sum, vector<int>lst, int idx)
{
	if (sum==0)
	{
		return true;
	}
	if (sum<0)
	{
		return false;
	}
	if (idx<0)
	{
		return false;
	}

	return solve(sum, lst, idx - 1) || solve(sum - lst[idx], lst, idx - 1);

}


int main() {

	int n, k;
	cin >> n >> k;
	vector<int>lst(n);
	for (int i=0;i<n;i++)
	{
		cin >> lst[i];
	}

	bool b = solve(k, lst, n-1);
	if (b)
	{
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	


}

