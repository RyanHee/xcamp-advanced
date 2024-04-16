#include <bits/stdc++.h>


using namespace std;
typedef pair<int, int> pii;


int inbetween(pair<pii, pii>hline, pair<pii, pii>vline) {
	if (vline.first.first >= hline.first.first && vline.first.first <= hline.second.first) {
		if (hline.first.second >= vline.first.second && hline.first.second <= vline.second.second) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int n;
	cin >> n;

	vector<pair<pii, pii>> h;
	vector<pair<pii, pii>> v;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		pii p = make_pair(x1, y1);
		pii p1 = make_pair(x2, y2);
		if (x1 == x2) {
			v.push_back(make_pair(p, p1));
		}
		else {
			h.push_back(make_pair(p, p1));
		}
	}

	int result = 0;
	for (auto hline : h) {
		for (auto vline : v) {
			result += inbetween(hline, vline);
		}
	}

	cout << result << endl;

	
}