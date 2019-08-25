#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, answer = 0;
int lab[8][8], temp[8][8];
vector<pair<int, int> > virus;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs() {
	queue<pair<int, int> > q;
	int final[8][8];
	int x, y, mx, my, count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			final[i][j] = temp[i][j];
	for (int i = 0; i < virus.size(); i++)
		q.push(virus[i]);
	while (q.empty() == 0) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			mx = x + dx[i];
			my = y + dy[i];
			if (mx >= 0 && mx < n && my >= 0 && my < m) {
				if (final[mx][my] == 0) {
					final[mx][my] = 2;
					q.push({ mx, my });
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (final[i][j] == 0)
				count += 1;
	answer = max(answer, count);
}

void add_wall(int count) {
	if (count == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				temp[i][j] = 1;
				add_wall(count + 1);
				temp[i][j] = 0;
			}
		}
	}
}

int main() {
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) virus.push_back({ i, j });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				for (int k = 0; k < n; k++)
					for (int l = 0; l < m; l++)
						temp[k][l] = lab[k][l];
				temp[i][j] = 1;
				add_wall(1);
				temp[i][j] = 0;
			}
		}
	}
	cout << answer;
	return 0;
}