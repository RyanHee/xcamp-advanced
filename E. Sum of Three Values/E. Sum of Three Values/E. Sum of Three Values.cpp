#include <bits/stdc++.h>
using namespace std;




int main()
{
    int n, x;
    cin >> n >> x;
    vector<int>lst(n);
    unordered_map<int, int>mp;
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
        mp[lst[i]] = i + 1;
    }
    

    for (int i=0;i<n-2;i++)
    {
	    for (int j=i+1;j<n;j++)
	    {
            int want = x - lst[i] - lst[j];
            if (mp.find(want)!=mp.end())
            {
                cout << i + 1 << " " << j + 1 << " " << mp[want] << endl;
                return 0;
            }
	    }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
