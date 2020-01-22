// time: O(3n^2) 초기 버전
#pragma warning(disable: 4996)
#include <cstdio>
#include <queue>
using namespace std;
int dist[1000][1000];

int solution(int** map, int n, int m) {
	int y, x, answer = 0, cnt;
	queue<pair<int, int> > path;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				path.push({ i,j });
				dist[i][j] = 0;
				while (path.empty() == 0) {
					y = path.front().first;
					x = path.front().second;
					path.pop();
					if (x != 0 && map[y][x - 1] == 0) {
						if (dist[y][x - 1] == 0 || dist[y][x] + 1 < dist[y][x - 1]) {
							dist[y][x - 1] = dist[y][x] + 1;
							path.push({ y,x - 1 });
						}
					}
					if (y != 0 && map[y - 1][x] == 0) {
						if (dist[y - 1][x] == 0 || dist[y][x] + 1 < dist[y - 1][x]) {
							dist[y - 1][x] = dist[y][x] + 1;
							path.push({ y - 1,x });
						}
					}
					if (x != m - 1 && map[y][x + 1] == 0) {
						if (dist[y][x + 1] == 0 || dist[y][x] + 1 < dist[y][x + 1]) {
							dist[y][x + 1] = dist[y][x] + 1;
							path.push({ y,x + 1 });
						}
					}
					if (y != n - 1 && map[y + 1][x] == 0) {
						if (dist[y + 1][x] == 0 || dist[y][x] + 1 < dist[y + 1][x]) {
							dist[y + 1][x] = dist[y][x] + 1;
							path.push({ y + 1,x });
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 0 && map[i][j] == 0) return -1;
			if (dist[i][j] > answer) answer = dist[i][j];
		}
	}
	return answer;
}

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int** tomatos = new int* [n];
	for (int i = 0; i < n; i++)
		tomatos[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &tomatos[i][j]);
	}
	printf("%d", solution(tomatos, n, m));
	delete[] tomatos;
	return 0;
}