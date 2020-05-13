// https://www.acmicpc.net/problem/14503
// Simulation
// time: O(nm) space: O(nm)
#include <iostream>
#include <vector>
using namespace std;
int cnt=0;

bool check(vector<vector<int>>& map, int r, int c) {
	if(r < 0 || c < 0) return 0;
	if(r >= map.size() || c >= map[0].size()) return 0;
	if(map[r][c] >= 1) return 0;
	return 1;
}
bool back(vector<vector<int>>& map, int r, int c) {
	if(r < 0 || c < 0) return 0;
	if(r >= map.size() || c >= map[0].size()) return 0;
	if(map[r][c] == 1) return 0;
	return 1;
}

void solution(vector<vector<int>>& map, int r, int c, int d) {
	if(map[r][c] == 0) {
		map[r][c] = 2;
		cnt += 1;
	}
	int i;
	if(d==0) i=3;
	else i=d-1;
	for(int j=0; j<4; j++) {
		if(i==0 && check(map, r-1, c) == 1) {
			solution(map, r-1, c, i);
			return;
		}
		if(i==1 && check(map, r, c+1) == 1) {
			solution(map, r, c+1, i);
			return;
		}
		if(i==2 && check(map, r+1, c) == 1) {
			solution(map, r+1, c, i);
			return;
		}
		if(i==3 && check(map, r, c-1) == 1) {
			solution(map, r, c-1, i);
			return;
		}
		if(i==0) i=3;
		else i-=1;
	}
	if(d==0 && back(map, r+1, c)) {
		solution(map, r+1, c, d);
		return;
	}
	else if(d==1 && back(map, r, c-1)) {
		solution(map, r, c-1, d);
		return;
	}
	else if(d==2 && back(map, r-1, c)) {
		solution(map, r-1, c, d);
		return;
	}
	else if(d==3 && back(map, r, c+1)) {
		solution(map, r, c+1, d);
		return;
	}
}

int main() {
	cin.tie(0);
	int n, m, r, c, d;
	cin >> n >> m;
	cin >> r >> c >> d;
	vector<vector<int>> map(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cin >> map[i][j];
	}
	solution(map, r, c, d);
	cout << cnt;
	return 0;
}