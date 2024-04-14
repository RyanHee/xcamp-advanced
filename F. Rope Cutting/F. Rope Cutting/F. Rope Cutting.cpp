#include <bits/stdc++.h>

using namespace std;

bool work(vector<double>lst, int k, double x) {
	int a = 0;
	for (double m : lst)
	{
		a += m / x;
	}
	if (a >= k)
	{
		return true;
	}
	return false;
}

int main() {
	//cout << __cplusplus << endl;
	int n, k;
	cin >> n >> k;
	vector<double>lst(n);
	double biggest = 0;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		if (lst[i] > biggest) {
			biggest = lst[i];
		}
	}
	double smallest = 1;
	while (smallest <= biggest)
	{
		double a = smallest + (biggest - smallest) / 2;
		double mid = round(a * 100) / 100;
		if (work(lst, k, mid)) {
			smallest = mid + 0.01;
		}
		else
		{
			biggest = mid - 0.01;
		}

	}
	cout << fixed << setprecision(2) << biggest << endl;
}