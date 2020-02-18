#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	vector<pair<int,int> > meeting;
	int n, s, e, cnt=0;
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s >> e;
		meeting.push_back({e, s});
	}
	sort(meeting.begin(), meeting.end());
	s = 0; e = 0;
	for(int i=0; i<n; i++) {
		if(meeting[i].second >= e) {
			e = meeting[i].first;
			s = meeting[i].second;
			cnt += 1;
		}
	}
	printf("%d", cnt);
	return 0;
}