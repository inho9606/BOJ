#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//bool comp(const int &a, const int &b) {
//	if(a[0] == b[0]) return
//}
int main() {
	cin.tie(0);
	int n;
	cin >> n;
	vector< vector<int> > board;
	vector<int> xy(2, 0);
	for (int i = 0; i < n; i++) {
		cin >> xy[0] >> xy[1];
		board.push_back(xy);
	}
	sort(board.begin(), board.end());
	for (int i = 0; i < board.size(); i++)
		cout << board[i][0] << " " << board[i][1] << "\n";
	return 0;
}