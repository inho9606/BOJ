// graph search BFS version
// time: O(n)
#pragma warning(disable: 4996) 
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void solution(vector<vector<int> > t, int n) {
	int v;
	vector<int> parent(n+1, 0);
	vector<bool> visited(n+1, 0);
	queue<int> bfs;
	visited[1] = 1;
	bfs.push(1);
	while(bfs.empty() == 0) {
		v = bfs.front();
		for(int j=0; j<t[v].size(); j++) {
			if(parent[t[v][j]] == 0) parent[t[v][j]] = v;
			if(visited[t[v][j]] == 0) {
				visited[t[v][j]] = 1;
				bfs.push(t[v][j]);
			}
		}
	bfs.pop();
	}
	for(int i=2; i<=n; i++)
		printf("%d\n", parent[i]);
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	vector<vector<int> > t(n+1);
	for(int i=1; i<=n-1; i++) {
		scanf("%d%d", &a, &b);
		t[a].push_back(b);
		t[b].push_back(a);
	}
	solution(t, n);
	return 0;
}