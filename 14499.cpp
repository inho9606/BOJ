// https://www.acmicpc.net/problem/14499
#include <iostream>
#include <vector>
using namespace std;
int x, y;
int roll(vector<vector<int>>& m, vector<int>& dice, int dir) {
	int tmp;
	if(dir == 1) {
		if(y+1 >= m[0].size()) return -1;
		y += 1;
		tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
	}
	else if(dir == 2) {
		if(y-1 < 0) return -1;
		y -= 1;
		tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
	}
	else if(dir == 3) {
		if(x-1 < 0) return -1;
		x -= 1;
		tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
	}
	else if(dir == 4) {
		if(x+1 >= m.size()) return -1;
		x += 1;
		tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
	}
	if(m[x][y] == 0) m[x][y] = dice[5];
	else {
		dice[5] = m[x][y];
		m[x][y] = 0;
	}
	return dice[0];
}
int main() {
	int n, m, k, top, dir;
	vector<int> dice(6,0);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	vector<vector<int>> map(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cin >> map[i][j];
	}
	for(int i=0; i<k; i++) {
		cin >> dir;
		top = roll(map, dice, dir);
		if(top != -1) printf("%d\n", top);
	}
	return 0;
}