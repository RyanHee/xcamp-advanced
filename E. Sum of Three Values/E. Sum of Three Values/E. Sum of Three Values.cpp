#include <bits/stdc++.h>
using namespace std;


bool solve(vector<int>lst, vector<int>data, int start, int end, int index, int sum)
{
    if (index == 3 && sum==0)
    {
        int s;
        for (int j = 0; j < 3; j++) {
            cout << data[j] << " ";
        }
            
        cout << endl;
        return true;
    }

    if (index == 3) {
        return false;
    }

    if (sum < 0) {
        return false;
    }

    bool ret;
    for (int i = start; i <= end && end - i + 1 >= 3 - index; i++)
    {
        data[index] = i + 1;
        ret = solve(lst, data, i + 1, end, index + 1, sum-lst[i]);
        if (ret) {
            return ret;
        }
    }
    return false;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int>lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }
    
    vector<int>data(3);

    bool b = solve(lst, data, 0, n-1, 0, x);
    if (!b) {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
