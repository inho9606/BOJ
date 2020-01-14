// time: O(v+e)
#pragma warning(disable: 4996) 
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

bool isBipartite(vector<vector<int> > graph, int n) {
	int v, des;
	queue<int> bfs;
	vector<int> visited(n+1, 0);
	for(int z=1; z<=n; z++) {
		if(visited[z] == 0) {
			visited[z] = 1;
			bfs.push(z);
			while(bfs.empty() == 0) {
				v = bfs.front();
				for(int i=0; i<graph[v].size(); i++) {
					des = graph[v][i];
					if(visited[des] == 0) {
						if(visited[v] == 1) visited[des] = 2;
						else if(visited[v] == 2) visited[des] = 1;
						bfs.push(des);
					}
					else {
						if(visited[des] == visited[v]) return 0;
					}
				}
				bfs.pop();
			}
		}
	}
	return 1;
}

void makeGraph() {
	int v, e, a, b;
	scanf("%d%d", &v, &e);
	vector<vector<int> > graph(v+1);
	for(int i=0; i<e; i++) {
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	if(isBipartite(graph, v) == 1) printf("YES\n");
	else printf("NO\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++)
		makeGraph();
	return 0;
}