#include <iostream>
#include <queue>
using namespace std;
bool visit[1001];
bool graph[1001][1001];

void dfs(int n, int v) {
	visit[v] = 1;
	printf("%d ", v);
	for(int i=1; i<=n; i++) {
		if(graph[v][i] == 1 && visit[i] == 0) {
			dfs(n, i);
		}
	}
}

void bfs(int n, int v) {
	queue<int> q;
	q.push(v);
	visit[v] = 1;
	while(q.empty() == 0) {
	v = q.front();
	printf("%d ", v);
		for(int i=1; i<=n; i++) {
			if(graph[v][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				q.push(i);
			}
		}
	q.pop();
	}
}

int main() {
	int a, b, n, m, v;
	cin >> n >> m >> v;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(n, v);
	printf("\n");
	for(int i=1; i<=n; i++)
		visit[i] = 0;
	bfs(n, v);
	return 0;
}