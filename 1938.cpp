// https://www.acmicpc.net/problem/1938
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int visited[50][50][2];
bool turnable(vector<string>& g, int i, int j) {
	if(i == 0 || i == g.size()-1 || j == 0 || j == g.size()-1) return 0;
	if(g[i-1][j-1] == '1' || g[i-1][j] == '1' || g[i-1][j+1] == '1') return 0;
	if(g[i][j-1] == '1' || g[i][j] == '1' || g[i][j+1] == '1') return 0;
	if(g[i+1][j-1] == '1' || g[i+1][j] == '1' || g[i+1][j+1] == '1') return 0;
	return 1;
}
int solution(vector<string>& g) {
	int cnt, answer=0, e[3], b[3], b_done = 0, e_done = 0;
	queue<pair<pair<int,int>,int> > q;
	for(int i=0; i<g.size(); i++) {
		for(int j=0; j<g.size(); j++) {
			if(g[i][j] == 'B' && b_done == 0) {
				b_done = 1;
				if(j+1 < g.size() && g[i][j+1] == 'B') {
					b[0] = i;
					b[1] = j+1;
					b[2] = 0;
				}
				else if(g[i+1][j] == 'B') {
					b[0] = i+1;
					b[1] = j;
					b[2] = 1;
				}
			}
			if(g[i][j] == 'E' && e_done == 0) {
				e_done = 1;
				if(j+1 < g.size() && g[i][j+1] == 'E') {
					e[0] = i;
					e[1] = j+1;
					e[2] = 0;
				}
				else {
					e[0] = i+1;
					e[1] = j;
					e[2] = 1;
				}
			}
		}
	}
	q.push({{b[0], b[1]}, b[2]});
	visited[b[0]][b[1]][b[2]] = 1;
	while(q.empty() == 0) {
		b[0] = q.front().first.first;
		b[1] = q.front().first.second;
		b[2] = q.front().second;
		q.pop();
		cnt = visited[b[0]][b[1]][b[2]];
//		printf("cuurent: %d %d %d %d\n", b[0], b[1], b[2], cnt);
		if(b[0] == e[0] && b[1] == e[1] && b[2] == e[2]) {
			answer = cnt-1;
			break;
		}
		if(b[2] == 0) {
			if(b[1]+2 < g.size() && g[b[0]][b[1]+2] != '1' && visited[b[0]][b[1]+1][0] == 0) {
				visited[b[0]][b[1]+1][0] = cnt+1;
				q.push({{b[0],b[1]+1},0});
			}
			if(b[1]-2 >= 0 && g[b[0]][b[1]-2] != '1' && visited[b[0]][b[1]-1][0] == 0) {
				visited[b[0]][b[1]-1][0] = cnt+1;
				q.push({{b[0],b[1]-1},0});
			}
			if(b[0]+1 < g.size() && g[b[0]+1][b[1]] != '1' && g[b[0]+1][b[1]-1] != '1' && g[b[0]+1][b[1]+1] != '1' && visited[b[0]+1][b[1]][0] == 0) {
				visited[b[0]+1][b[1]][0] = cnt+1;
				q.push({{b[0]+1,b[1]},0});
			}
			if(b[0]-1 >= 0 && g[b[0]-1][b[1]] != '1' && g[b[0]-1][b[1]-1] != '1' && g[b[0]-1][b[1]+1] != '1' && visited[b[0]-1][b[1]][0] == 0) {
				visited[b[0]-1][b[1]][0] = cnt+1;
				q.push({{b[0]-1,b[1]},0});
			}
			if(visited[b[0]][b[1]][1] == 0 && turnable(g, b[0], b[1]) == 1) {
				visited[b[0]][b[1]][1] = cnt+1;
				q.push({{b[0],b[1]},1});
			}
		}
		else {
			if(b[0]+2 < g.size() && g[b[0]+2][b[1]] != '1' && visited[b[0]+1][b[1]][1] == 0) {
				visited[b[0]+1][b[1]][1] = cnt+1;
				q.push({{b[0]+1,b[1]},1});
			}
			if(b[0]-2 >= 0 && g[b[0]-2][b[1]] != '1' && visited[b[0]-1][b[1]][1] == 0) {
				visited[b[0]-1][b[1]][1] = cnt+1;
				q.push({{b[0]-1,b[1]},1});
			}
			if(b[1]+1 < g.size() && g[b[0]][b[1]+1] != '1' && g[b[0]-1][b[1]+1] != '1' && g[b[0]+1][b[1]+1] != '1' && visited[b[0]][b[1]+1][1] == 0) {
				visited[b[0]][b[1]+1][1] = cnt+1;
				q.push({{b[0],b[1]+1},1});
			}
			if(b[1]-1 >= 0 && g[b[0]][b[1]-1] != '1' && g[b[0]-1][b[1]-1] != '1' && g[b[0]+1][b[1]-1] != '1' && visited[b[0]][b[1]-1][1] == 0) {
				visited[b[0]][b[1]-1][1] = cnt+1;
				q.push({{b[0],b[1]-1},1});
			}
			if(visited[b[0]][b[1]][0] == 0 && turnable(g, b[0], b[1]) == 1) {
				visited[b[0]][b[1]][0] = cnt+1;
				q.push({{b[0],b[1]},0});
			}
		}
	}
	return answer;
}
int main() {
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> ground(n);
	for(int i=0; i<n; i++)
		cin >> ground[i];
	cout << solution(ground);
	return 0;
}