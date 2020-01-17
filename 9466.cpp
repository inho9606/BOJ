// Must use DFS to find Cycling, or use union and disjoint set
// Time over
#pragma warning(disable: 4996) 
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
bool cycle[100001], visited[100001];

bool dfs(vector<int> team, int v, int start) {
	visited[v] = 1;
	if(team[v] == start) { cycle[v] = 1; return 1; }
	if(cycle[v] == 1 || (visited[team[v]] == 1 && team[v] != start)) return 0;
	if(dfs(team, team[v], start) == 1) { cycle[v] = 1; //visited[v] = 0; return 1; }
//	visited[v] = 0;
	return 0;
}

int solution(int n) {
	int answer=0, student;
	vector<int> team(n+1);
	for(int i=1; i<=n; i++) {
		scanf("%d", &team[i]);
	}
	for(int i=1; i<=n; i++) {
		cycle[i] = 0;
		visited[i] = 0;
	}
	for(int i=1; i<=n; i++)
		if(cycle[i] == 0) dfs(team, i, i);
	for(int i=1; i<=n; i++)
		if(cycle[i] == 0) {
			answer++;
//			printf("%d ", i);
		}
	return answer;
}

int main() {
	int t, n;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		scanf("%d", &n);
		printf("%d\n", solution(n));
	}
	return 0;
}