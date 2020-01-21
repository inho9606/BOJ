// 트리 지름: 임의의 정점 x에서 도달할 수 있는 임의의 정점까지의 가중치 합이 가장 큰 정점을 y라고 할 때, 정점 y로부터 도달 가능한 정점 Z 중 가중치 합이 가장큰 값을 트리의 지름이라고 한다.
// 그래프에서 임의의 정점 x에서 임의의 정점 y까지의 가중치/거리를 계산할 때는 BFS를 사용하는 것이 유리하다. DFS는 이전 계산값 기록하기 어려움(전역변수 사용 필요)
// time: O(n) n is the number of vertexes/nodes
#pragma warning(disable: 4996) 
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<pair<int,int> > > tree, vector<int> dist, int v, int mode) {
	int w=0, p=0;
	queue<int> path;
	dist[v] = 0;
	path.push(v);
	while(path.empty() == 0) {
		v = path.front();
		path.pop();
		for(int i=0; i<tree[v].size(); i++) {
			if(dist[tree[v][i].first] == -1) {
				dist[tree[v][i].first] = dist[v] + tree[v][i].second;
				path.push(tree[v][i].first);
			}
		}
	}
	for(int i=1; i<dist.size(); i++) {
//		printf("%d to %d\n", i, dist[i]);
		if(dist[i] > w) { w = dist[i]; p = i; }
	}
//	printf("%d distance %d\n", p, w);
	if(mode == 0) return p;
	else return w;
}

int solution(vector<vector<pair<int,int> > > tree, int n) {
	int answer, longest;
	vector<int> dist(n+1, -1);
	longest = bfs(tree, dist, 1, 0);
	answer = bfs(tree, dist, longest, 1);
	return answer;
}

int main() {
	int n, v, u, w;
	scanf("%d", &n);
	vector<vector<pair<int,int> > > tree(n+1);
	for(int i=0; i<n; i++) {
		scanf("%d", &v);
		while(1) {
			scanf("%d", &u);
			if(u==-1) break;
			scanf("%d", &w);
			tree[v].push_back({u, w});
		}
	}
	printf("%d", solution(tree, n));
	return 0;
}