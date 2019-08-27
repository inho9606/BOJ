//https://www.acmicpc.net/problem/2206
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
string map[1000];
int n, m;
int dist[1000][1000][2];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0,1,-1 };

int solution() {
	int answer = -1, nx, ny;
	queue<pair<pair<int, int>, int> > q;
	q.push({ {0,0},0 });
	dist[0][0][0] = 1;
	while (q.empty() == 0) {
				if (q.front().first.first == n - 1 && q.front().first.second == m - 1) {
					answer = dist[q.front().first.first][q.front().first.second][q.front().second];
					break;
				}
		for (int i = 0; i < 4; i++) {
			nx = q.front().first.first + dx[i];
			ny = q.front().first.second + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (map[nx][ny] == '0' && dist[nx][ny][q.front().second] == 0) {
					q.push({ {nx,ny}, q.front().second });
					dist[nx][ny][q.front().second] = dist[q.front().first.first][q.front().first.second][q.front().second] + 1;
				}
				else if (map[nx][ny] == '1' && q.front().second == 0 && dist[nx][ny][0] == 0) {
					q.push({ {nx, ny}, 1 });
					dist[nx][ny][1] = dist[q.front().first.first][q.front().first.second][0] + 1;
				}
			}
		}
		q.pop();
	}
	return  answer;
}

int main() {
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	cout << solution();
	return 0;
}