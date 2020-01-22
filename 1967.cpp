// 트리: 사이클이 없는 무방향 그래프
// 트리의 지름: 트리에서 임의의 두 노드를 잡아당겼을 때 그 거리가 최대가 되어 다른 노드들이 해당 노드의 안쪽에 위치하여 원이 되는 노드의 길이
// 트리의 지름 구하는 방법: 임의의 노드 x로부터 가중치의 합(거리가 가장 긴) 노드 y를 찾는다. 노드 y로부터 가중치의 합(거리가 가장 긴) 노드 z까지의 거리가 트리의 지름이 된다.
// time: O(n) n is the number of nodes on given tree.
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<pair<int,int> > > tree, int n, int start, int mode) {
	int answer, v, d=0;
	vector<int> dist(n+1, -1);
	queue<int> path;
	dist[start] = 0;
	path.push(start);
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
	for(int i=1; i<=n; i++)
		if(dist[i] > d) { d = dist[i]; answer = i; }
	if(mode == 0) return answer;
	else return d;
}

int main() {
	int n, v, u, w, diameter;
	scanf("%d", &n);
	vector<vector<pair<int,int> > > tree(n+1);
	for(int i=0; i<n; i++) {
		scanf("%d%d%d", &v, &u, &w);
		tree[v].push_back({u, w});
		tree[u].push_back({v, w});
	}
	diameter = bfs(tree, n, 1, 0);
	printf("%d", bfs(tree, n, diameter, 1));
	return 0;
}