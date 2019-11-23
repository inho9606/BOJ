#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,string> a, pair<int,string> b) {
	return a.first < b.first;
}

int main() {
	int n;
	cin.tie(0);
	cin >> n;
	vector<pair<int,string> > p(n);
	for(int i=0; i<n; i++)
		cin >> p[i].first >> p[i].second;
	stable_sort(p.begin(), p.end(), compare);
	for(int i=0; i<n; i++)
		cout << p[i].first << " " << p[i].second << "\n";
	return 0;
}