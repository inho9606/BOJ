#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int whitematch(string* board, int y, int x) {
	string white[2] = {
		{"WB"},
		{"BW"},
	};
	int count = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != white[i % 2][j % 2]) count++;
	return count;
}

int blackmatch(string* board, int y, int x) {
	string black[2] = {
		{"BW"},
		{"WB"},
	};
	int count = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != black[i % 2][j % 2]) count++;
	return count;
}

int solution(string* board, int n, int m) {
	int answer = 1000000;
	for (int i = n - 8; i >= 0; i--) {
		for (int j = m - 8; j >= 0; j--)
			answer = min(answer, min(whitematch(board, i, j), blackmatch(board, i, j)));
	}
	return answer;
}
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	string* board = new string[n];
	for (int i = 0; i < n; i++)
		cin >> board[i];
	cout << solution(board, n, m);
	delete[] board;
	return 0;
}