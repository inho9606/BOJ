// Ʈ�� ����: ������ ���� x���� ������ �� �ִ� ������ ���������� ����ġ ���� ���� ū ������ y��� �� ��, ���� y�κ��� ���� ������ ���� Z �� ����ġ ���� ����ū ���� Ʈ���� �����̶�� �Ѵ�.
// �׷������� ������ ���� x���� ������ ���� y������ ����ġ/�Ÿ��� ����� ���� BFS�� ����ϴ� ���� �����ϴ�. DFS�� ���� ��갪 ����ϱ� �����(�������� ��� �ʿ�)
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