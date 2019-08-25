#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int w, h, n, x, y, answer = 0;
	cin.tie(0);
	cin >> w >> h >> n;
	vector<pair<pair<int, int>, int> > st;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		st.push_back({ { x, y }, i });
		if (x != y) st.push_back({ { y, x }, i });
	}
	for (int i = 0; i < st.size(); i++) {
		for (int j = i + 1; j < st.size(); j++) {
		if(st[i].second == st[j].second) continue;
			if (st[i].first.first + st[j].first.first <= w && max(st[i].first.second, st[j].first.second) <= h) {
				answer = max(answer, (st[i].first.first * st[i].first.second) + (st[j].first.first * st[j].first.second));
			}
			else if (st[i].first.second + st[j].first.second <= h && max(st[i].first.first, st[j].first.first) <= w) {
				answer = max(answer, st[i].first.first * st[i].first.second + st[j].first.first * st[j].first.second);
			}
			else if (st[i].first.first + st[j].first.first <= h && max(st[i].first.second, st[j].first.second) <= w) {
				answer = max(answer, st[i].first.first * st[i].first.second + st[j].first.first * st[j].first.second);
			}
			else if (st[i].first.second + st[j].first.second <= w && max(st[i].first.first, st[j].first.first) <= h) {
				answer = max(answer, st[i].first.first * st[i].first.second + st[j].first.first * st[j].first.second);
			}

		}
	}
	cout << answer;
	return 0;
}