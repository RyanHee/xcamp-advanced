#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int>pii;



int main()
{
    int n, x;
    cin >> n >> x;
    //vector<int>lst(n);
    vector<pii>vp(n);
    for (int i = 0; i < n; i++) {
        pii p;
        cin >> p.first;
        p.second = i + 1;
        vp[i] = p;
    }

    sort(vp.begin(), vp.end());

    for (int i = 0; i < n; i++)
    {
        int want = x - vp[i].first;
        int left = 0;
        int right = n - 1;

        while (left < right) {
            if (right != i && left != i && vp[left].first + vp[right].first == want) {
                cout << vp[i].second << " " << vp[left].second << " " << vp[right].second << endl;
                return 0;
            }
            else if (vp[left].first + vp[right].first < want) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
