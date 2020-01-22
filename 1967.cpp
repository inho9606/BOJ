// Ʈ��: ����Ŭ�� ���� ������ �׷���
// Ʈ���� ����: Ʈ������ ������ �� ��带 ��ƴ���� �� �� �Ÿ��� �ִ밡 �Ǿ� �ٸ� ������ �ش� ����� ���ʿ� ��ġ�Ͽ� ���� �Ǵ� ����� ����
// Ʈ���� ���� ���ϴ� ���: ������ ��� x�κ��� ����ġ�� ��(�Ÿ��� ���� ��) ��� y�� ã�´�. ��� y�κ��� ����ġ�� ��(�Ÿ��� ���� ��) ��� z������ �Ÿ��� Ʈ���� ������ �ȴ�.
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