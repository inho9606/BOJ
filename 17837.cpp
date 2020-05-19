// https://www.acmicpc.net/problem/17837
// time: O(n^2+k^3) space: O(n^2+k)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define WHITE 0
#define RED 1
#define BLUE 2
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
using namespace std;
// time: O(k^2) space: O(k)
bool move_all(vector<vector<int>>& board, vector<vector<stack<int>>>& check, vector<vector<int>>& pawn, int id, int py, int px, int d, int y, int x) {
	int i;
	for(i=0; i<pawn.size(); i++) {
		if(pawn[i][3] == id) break;
	}
	if(y < 1 || x < 1 || y >= board.size() || x >= board.size() || board[y][x] == BLUE) {
		if(d == RIGHT) pawn[i][2] = LEFT;
		else if(d == LEFT) pawn[i][2] = RIGHT;
		else if(d == UP) pawn[i][2] = DOWN;
		else if(d == DOWN) pawn[i][2] = UP;
		if(pawn[i][2] == RIGHT && px+1 < board.size() && board[py][px+1] != BLUE) {
			if(move_all(board, check, pawn, id, py, px, pawn[i][2], py, px+1) == 0) return 0;
		}
		else if(pawn[i][2] == LEFT && px-1 >= 1 && board[py][px-1] != BLUE) {
			if(move_all(board, check, pawn, id, py, px, pawn[i][2], py, px-1) == 0) return 0;
		}
		else if(pawn[i][2] == UP && py-1 >= 1 && board[py-1][px] != BLUE) {
			if(move_all(board, check, pawn, id, py, px, pawn[i][2], py-1, px) == 0) return 0;
		}
		else if(pawn[i][2] == DOWN && py+1 < board.size() && board[py+1][px] != BLUE) {
			if(move_all(board, check, pawn, id, py, px, pawn[i][2], py+1, px) == 0) return 0;
		}
	}
	else if(board[y][x] == WHITE) {
		stack<int> temp;
		while(check[py][px].top() != id) {
			for(int j=0; j<pawn.size(); j++) {
				if(pawn[j][3] == check[py][px].top()) {
					pawn[j][0] = y;
					pawn[j][1] = x;
					break;
				}
			}
			temp.push(check[py][px].top());
			check[py][px].pop();
		}
		pawn[i][0] = y;
		pawn[i][1] = x;
		temp.push(check[py][px].top());
		check[py][px].pop();
		while(temp.empty() == 0) {
			check[y][x].push(temp.top());
			temp.pop();
		}
		if(check[y][x].size() >= 4) return 0;
	}
	else if(board[y][x] == RED) {
		queue<int> temp;
		while(check[py][px].top() != id) {
			for(int j=0; j<pawn.size(); j++) {
				if(pawn[j][3] == check[py][px].top()) {
					pawn[j][0] = y;
					pawn[j][1] = x;
					break;
				}
			}
			temp.push(check[py][px].top());
			check[py][px].pop();
		}
		pawn[i][0] = y;
		pawn[i][1] = x;
		temp.push(check[py][px].top());
		check[py][px].pop();
		while(temp.empty() == 0) {
			check[y][x].push(temp.front());
			temp.pop();
		}
		if(check[y][x].size() >= 4) return 0;
	}
	return 1;
}

// time: O(k^3) space: O(1)
bool move(vector<vector<int>>& board, vector<vector<stack<int>>>& check, vector<vector<int>>& pawn) {
	int y, x, d, ID;
	for(int i=0; i<pawn.size(); i++) {
		y = pawn[i][0];
		x = pawn[i][1];
		d = pawn[i][2];
		ID = pawn[i][3];
		if(d==RIGHT) {
			if(move_all(board, check, pawn, ID, y, x, d, y, x+1) == 0) return 0;
		}
		else if(d==LEFT) {
			if(move_all(board, check, pawn, ID, y, x, d, y, x-1) == 0) return 0;
		}
		else if(d==UP) {
			if(move_all(board, check, pawn, ID, y, x, d, y-1, x) == 0) return 0;
			if(check[y-1][x].size() >= 4) return 0;
		}
		else if(d==DOWN) {
			if(move_all(board, check, pawn, ID, y, x, d, y+1, x) == 0) return 0;
		}
	}
	return 1;
}

int main() {
	int turn=1, n, k;
	cin.tie(0);
	cin >> n >> k;
	vector<vector<int>> board(n+1, vector<int>(n+1));
	vector<vector<stack<int>>> check(n+1, vector<stack<int>>(n+1));
	vector<vector<int>> pawn(k, vector<int>(4));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			cin >> board[i][j];
	}
	for(int i=0; i<k; i++) {
		for(int j=0; j<3; j++) {
			cin >> pawn[i][j];
		}
		pawn[i][3] = i+1;
		check[pawn[i][0]][pawn[i][1]].push(i+1);
	}
	while(move(board, check, pawn) == 1) {
		if(turn >= 1000) { turn = -1; break; }
		turn += 1;
	}
	printf("%d", turn);
	return 0;
}