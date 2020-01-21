// 최단경로는 BFS
// time: O(n) n is the number of the available path on given map
#include <cstdio>
#include <queue>
using namespace std;
int dist[100][100];
char map[100][100];

int solution(int n, int m) {
	int y, x, answer;
	queue<pair<int,int> > path;
	path.push({0,0});
	dist[0][0] = 1;
	while(path.empty() == 0) {
		y = path.front().first;
		x = path.front().second;
		path.pop();
		if(x != m-1 && map[y][x+1] == '1') {
			if(dist[y][x+1] == 0) {
				dist[y][x+1] = dist[y][x]+1;
				path.push({y, x+1});
			}
		}
		if(y != n-1 && map[y+1][x] == '1') {
			if(dist[y+1][x] == 0) {
				dist[y+1][x] = dist[y][x]+1;
				path.push({y+1, x});
			}
		}
		if(x != 0 && map[y][x-1] == '1') {
			if(dist[y][x-1] == 0) {
				dist[y][x-1] = dist[y][x]+1;
				path.push({y, x-1});
			}
		}
		if(y != 0 && map[y-1][x] == '1') {
			if(dist[y-1][x] == 0) {
				dist[y-1][x] = dist[y][x]+1;
				path.push({y-1, x});
			}
		}
	}
	answer = dist[n-1][m-1];
	return answer;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%s", map[i]);
	printf("%d", solution(n, m));
	return 0;
}