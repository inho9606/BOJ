#pragma warning(disable: 4996) 
#include <cstdio>
#include <queue>
using namespace std;
bool graph[1001][1001];
bool visited[1001];

int bfs(int n, int v) {
	queue<int> q;
	visited[v] = 1;
	q.push(v);
	while(q.empty() == 0) {
		v = q.front();
		for(int i=1; i<=n; i++)
			if(graph[v][i] == 1 && visited[i] == 0) {
				visited[i] = 1;
				q.push(i);
			}
		q.pop();
	}
	return 1;
}

int main() {
	int n, m, u,v, cnt=0;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%d%d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	for(int i=1; i<=n; i++) {
		if(visited[i] == 0) cnt += bfs(n, i);
	}
	printf("%d", cnt);
	return 0;
}