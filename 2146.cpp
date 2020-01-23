// time: O(n^2)
#pragma warning(disable: 4996)
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int check(int** map, int n, int i, int j, int from) {
	int y, x;
	vector<vector<int> > dist;
	queue<pair<int,int> > path;
	dist.assign(n, vector<int>(n, 0));
	dist[i][j] = 1;
	path.push({i, j});
	while(path.empty() == 0) {
		y = path.front().first;
		x = path.front().second;
		path.pop();
		if(x != 0 && map[y][x-1] != 0 && map[y][x-1] != from) return dist[y][x];
		if(x != n-1 && map[y][x+1] != 0 && map[y][x+1] != from) return dist[y][x];
		if(y != 0 && map[y-1][x] != 0 && map[y-1][x] != from) return dist[y][x];
		if(y != n-1 && map[y+1][x] != 0 && map[y+1][x] != from) return dist[y][x];
		if(x != 0 && map[y][x-1] == 0 && dist[y][x-1] == 0) {
			dist[y][x-1] = dist[y][x]+1;
			path.push({y,x-1});
		}
		if(x != n-1 && map[y][x+1] == 0 && dist[y][x+1] == 0) {
			dist[y][x+1] = dist[y][x]+1;
			path.push({y,x+1});
		}
		if(y != 0 && map[y-1][x] == 0 && dist[y-1][x] == 0) {
			dist[y-1][x] = dist[y][x]+1;
			path.push({y-1,x});
		}
		if(y != n-1 && map[y+1][x] == 0 && dist[y+1][x] == 0) {
			dist[y+1][x] = dist[y][x]+1;
			path.push({y+1,x});
		}
	}
	return 1000000;
}

int solution(int** map, int n) {
	int d, answer=1000000, y, x, island=1;
	queue<pair<int,int> > path;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j] == 1) {
				island += 1;
				map[i][j] = island;
				path.push({i,j});
				while(path.empty() == 0) {
					y = path.front().first;
					x = path.front().second;
					path.pop();
					if(x != 0 && map[y][x-1] == 1) {
						map[y][x-1] = island;
						path.push({y,x-1});
					}
					if(x != n-1 && map[y][x+1] == 1) {
						map[y][x+1] = island;
						path.push({y,x+1});
					}
					if(y != 0 && map[y-1][x] == 1) {
						map[y-1][x] = island;
						path.push({y-1,x});
					}
					if(y != n-1 && map[y+1][x] == 1) {
						map[y+1][x] = island;
						path.push({y+1,x});
					}
				}
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(map[i][j] != 0) {
				island = map[i][j];
				if(j != 0 && map[i][j-1] == 0) {
					d = check(map, n, i, j-1, island);
					if(d < answer) answer = d;
				}
				if(j != n-1 && map[i][j+1] == 0) {
					d = check(map, n, i, j+1, island);
					if(d < answer) answer = d;
				}
				if(i != 0 && map[i-1][j] == 0) {
					d = check(map, n, i-1, j, island);
					if(d < answer) answer = d;
				}
				if(i != n-1 && map[i+1][j] == 0) {
					d = check(map, n, i+1, j, island);
					if(d < answer) answer = d;
				}
			}
		}
	}
	return answer;
}

int main() {
	int n;
	scanf("%d", &n);
	int** map = new int*[n];
	for(int i=0; i<n; i++)
		map[i] = new int[n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			scanf("%d", &map[i][j]);
	}
	printf("%d", solution(map, n));
	delete[] map;
	return 0;
}