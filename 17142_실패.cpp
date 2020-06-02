// https://www.acmicpc.net/problem/17142
// 바이러스가 퍼지는 방식을 이해하지 못한듯.. 이해한대로 구현
#include <iostream>
#include <vector>
#include <queue>
#define BLANK 0
#define WALL 1
#define VIRUS 2
using namespace std;
int answer = 100000;

void spread(vector<vector<int>> l, int sec) {
	int y, x;
	bool done = true;
	queue<pair<int,int>> q, tmp;
	vector<vector<int>> copied(l.begin(), l.end());
	for (int i = 0; i < l.size(); i++) {
		for (int j = 0; j < l.size(); j++) {
			if (l[i][j] == 0 || l[i][j] == 2) done = false;
				if (j - 1 >= 0 && l[i][j - 1] != WALL) copied[i][j - 1] = 3;
			if (l[i][j] == 3) {
				q.push({i,j});
			}
		}
	}
	while(q.empty() == 0) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (y + 1 < l.size()) {
			if(copied[y+1][x] == BLANK) { q.push({y+1,x}); copied[y + 1][x] = 3; }
			else if(copied[y+1][x] == 2) tmp.push({y+1,x});
		}
		if (x + 1 < l.size()) {
			if(copied[y][x+1] == BLANK) { q.push({y,x+1}); copied[y][x+1] = 3; }
			else if(copied[y][x+1] == 2) tmp.push({y,x+1});
		}
		if (y-1 >= 0) {
			if(copied[y-1][x] == BLANK) { q.push({y-1,x}); copied[y-1][x] = 3; }
			else if(copied[y-1][x] == 2) tmp.push({y-1,x});
		}
		if (x-1 >= 0) {
			if(copied[y][x-1] == BLANK) { q.push({y,x-1}); copied[y][x-1] = 3; }
			else if(copied[y][x-1] == 2) tmp.push({y,x-1});
		}
	}
	while(tmp.empty() == 0) {
		copied[tmp.front().first][tmp.front().second] = 3;
		tmp.pop();
	}
	if (done == true) {
		if (sec < answer) answer = sec;
		return;
	}
	else spread(copied, sec + 1);
}

void choose(vector<vector<int>>& l, vector<pair<int, int>>& v, vector<pair<int, int>>& tmp, int j, int cnt) {
	if (cnt >= tmp.size()) {
		for (int i = 0; i < tmp.size(); i++) {
			l[tmp[i].first][tmp[i].second] = 3;
			printf("%d %d \n", tmp[i].first, tmp[i].second);
		}
		printf("\n");
		spread(l, 0);
		printf("%d초 걸림\n", answer);
		for (int i = 0; i < tmp.size(); i++)
			l[tmp[i].first][tmp[i].second] = 2;
		return;
	}
	for (int i = j + 1; i < v.size(); i++) {
		tmp[cnt] = { v[i].first, v[i].second };
		choose(l, v, tmp, i, cnt + 1);
	}
}
void solution(vector<vector<int>>& l, vector<pair<int, int>>& v, int m) {
	printf("활성 %d/%d\n", m, v.size());
	vector<pair<int, int>> tmp(m);
	choose(l, v, tmp, -1, 0);
}
int main() {
	int n, m;
	cin.tie(0);
	cin >> n >> m;
	vector<vector<int>> lab(n, vector<int>(n));
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == VIRUS) v.push_back({ i,j });
		}
	}
	solution(lab, v, m);
	cout << answer;
	return 0;
}