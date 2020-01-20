// time: O(nm)
#pragma warning(disable: 4996) 
#include <cstdio>
#include <queue>
using namespace std;

int solution(int** map, int n, int m) {
	int cnt=0, y, x;
	queue<pair<int, int> > bfs;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(map[i][j] == 1) {
				cnt += 1;
				map[i][j] = 2;
				bfs.push({i,j});
				while(bfs.empty() == 0) {
					y = bfs.front().first;
					x = bfs.front().second;
					bfs.pop();
					if(x != 0) {
						if(map[y][x-1] == 1) {
							map[y][x-1] = 2;
							bfs.push({y, x-1});
						}
						if(y != 0 && map[y-1][x-1] == 1) {
							map[y-1][x-1] = 2;
							bfs.push({y-1, x-1});
						}
						if(y != n-1 && map[y+1][x-1] == 1) {
							map[y+1][x-1] = 2;
							bfs.push({y+1, x-1});
						}
					}
					if(x != m-1) {
						if(map[y][x+1] == 1) {
							map[y][x+1] = 2;
							bfs.push({y, x+1});
						}
						if(y != 0 && map[y-1][x+1] == 1) {
							map[y-1][x+1] = 2;
							bfs.push({y-1, x+1});
						}
						if(y != n-1 && map[y+1][x+1] == 1) {
							map[y+1][x+1] = 2;
							bfs.push({y+1, x+1});
						}
					}
					if(y != 0 && map[y-1][x] == 1) {
						map[y-1][x] = 2;
						bfs.push({y-1, x});
					}
					if(y != n-1 && map[y+1][x] == 1) {
						map[y+1][x] = 2;
						bfs.push({y+1, x});
					}
				}
			}
		}
	}
	return cnt;
}

int main() {
	int n, m;
	while(1) {
		scanf("%d%d", &m, &n);
		if(n == 0 && m == 0) break;
		int** map = new int*[n];
		for(int i=0; i<n; i++)
			map[i] = new int[m];
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		printf("%d\n", solution(map, n, m));
		delete[] map;
	}
	return 0;
}