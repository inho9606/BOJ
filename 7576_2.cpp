// time: O(2n^2) n^2에 끝나야 하는데 탐색하는시간을 줄이지 못해서 시간초과
#pragma warning(disable: 4996)
#include <cstdio>
#include <queue>
using namespace std;
int dist[1000][1000];
int needs=0;

void solution(int** map, int n, int m, int i, int j) {
	int y, x;
	queue<pair<int,int> > path;
	path.push({i,j});
	dist[i][j] = 0;
	while(path.empty() == 0) {
		y = path.front().first;
		x = path.front().second;
		path.pop();
		if(x != 0 && map[y][x-1] == 0) {
			if(dist[y][x-1] == 0) needs--;
			if(dist[y][x-1] == 0 || dist[y][x]+1 < dist[y][x-1]) { 
				dist[y][x-1] = dist[y][x] + 1;
				path.push({y,x-1});
			}
		}
		if(y != 0 && map[y-1][x] == 0) {
			if(dist[y-1][x] == 0) needs--;
			if(dist[y-1][x] == 0 || dist[y][x]+1 < dist[y-1][x]) {
				dist[y-1][x] = dist[y][x] + 1;
				path.push({y-1,x});
			}
		}
		if(x != m-1 && map[y][x+1] == 0) {
			if(dist[y][x+1] == 0) needs--;
			if(dist[y][x+1] == 0 || dist[y][x]+1 < dist[y][x+1]) {
				dist[y][x+1] = dist[y][x] + 1;
				path.push({y,x+1});
			}
		}
		if(y != n-1 && map[y+1][x] == 0) {
			if(dist[y+1][x] == 0) needs--;
			if(dist[y+1][x] == 0 || dist[y][x]+1 < dist[y+1][x]) {
				dist[y+1][x] = dist[y][x] + 1;
				path.push({y+1,x});
			}
		}
	}
}

int main() {
	int m, n, answer=0;
	queue<pair<int,int> > t;
	scanf("%d%d", &m, &n);
	int** tomatos = new int*[n];
	for(int i=0; i<n; i++)
		tomatos[i] = new int[m];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &tomatos[i][j]);
			if(tomatos[i][j] == 1) t.push({i,j});
			else if(tomatos[i][j] == 0) needs++;
		}
	}
	while(t.empty() == 0) {
		solution(tomatos, n, m, t.front().first, t.front().second);
		t.pop();
	}
	delete[] tomatos;
	if(needs > 0) { printf("%d", -1); return 0; }
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(dist[i][j] > answer) answer = dist[i][j];
		}
	}
	printf("%d", answer);
	return 0;
}