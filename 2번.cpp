#include <iostream>
#include <queue>
using namespace std;

int solution(int board[][9], int s) {
	int n = 0, y, x;
	queue<pair<int, int> > wrong;
	bool check[10] = {0,0,0,0,0,0,0,0,0,0};
	if (s < 9) {
		y = 0; x = s; }
	else if (s >= 9 && s < 18) {
		y = 3; x = s - 9; 
	}
	else {
		y = 6; x = s - 18;
	}
	for (int i = y+2; i >= y; i--) {
		for (int j = x+2; j >= x; j--) {
			if (check[board[i][j] - 1] == 0) check[board[i][j] - 1] = 1;
			else {
				wrong.push({ i+1, j+1 });
			}
		}
	}
	while (wrong.empty() == 0) {
		for (int i = 0; i < 10; i++) {
			if (check[i] == 0) {
				cout << " " << wrong.front().first << " " << wrong.front().second << " " << i+1;
				wrong.pop();
				check[i] = 1;
				n += 1;
				break;
			}
		}
	}
	return n;
}
void run() {
	int k, n = 0;
	int board[9][9];
	cin >> k;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < 9; i++) {
		n += solution(board, i * 3);
		if (n >= k) break;
	}
}

int main() {
	int t;
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "#" << i+1;
		run();
		cout << "\n";
	}
	return 0;
}