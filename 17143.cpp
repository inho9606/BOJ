// https://www.acmicpc.net/problem/17143
// Wrong answer... Why? It might be time exceed though.
#include <iostream>
#include <vector>
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
using namespace std;

void kill_shark(vector<vector<int>>& s, int r, int c) {
	for(int i=0; s.size(); i++) {
		if(s[i][0] == r && s[i][1] == c) {
			s[i][0] = 0;
			s[i][1] = 0;
			return;
		}
	}
}
void reverse_dir(vector<int>& shark) {
			if(shark[3] == UP) shark[3] = DOWN;
	else if(shark[3] == DOWN) shark[3] = UP;
	else if(shark[3] == LEFT) shark[3] = RIGHT;
	else if(shark[3] == RIGHT) shark[3] = LEFT;
}
void move(vector<vector<pair<int,int>>>& p, vector<int>& shark) {
		int s = shark[2];
		p[shark[0]][shark[1]].first -= 1;
	while(s > 0) {
		if(shark[3] == UP) {
			shark[0] -= s;
			if(shark[0] >= 1 && shark[0] < p.size()) s = 0;
			else {
				s = 1-shark[0];
				shark[0] = 1;
				reverse_dir(shark);
			}
		}
		else if(shark[3] == LEFT) {
			shark[1] -= s;
			if(shark[1] >= 1) s = 0;
			else {
				s = 1-shark[1];
				shark[1] = 1;
				reverse_dir(shark);
			}
		}
		else if(shark[3] == DOWN) {
			shark[0] += s;
			if(shark[0] < p.size()) s = 0;
			else {
				s = shark[0]-p.size()+1;
				shark[0] = p.size()-1;
				reverse_dir(shark);
			}
		}
		else if(shark[3] == RIGHT) {
			shark[1] += s;
			if(shark[1] < p[1].size()) s = 0;
			else {
				s = shark[1]-p[1].size()+1;
				shark[1] = p[1].size()-1;
				reverse_dir(shark);
			}
		}
	}
	if(p[shark[0]][shark[1]].first == 0)
		p[shark[0]][shark[1]] = {1, shark[4]};
	else {
		p[shark[0]][shark[1]].first += 1;
		if(shark[4] > p[shark[0]][shark[1]].second) p[shark[0]][shark[1]].second = shark[4];
	}
}
void eat(vector<vector<pair<int,int>>>& p, vector<vector<int>>& s) {
	for(int i=1; i<p.size(); i++) {
		for(int j=1; j<p[1].size(); j++) {
			if(p[i][j].first > 1) {
				for(int k=0; k<s.size(); k++) {
					if(s[k][0] == i && s[k][1] == j && s[k][4] == p[i][j].second) {
						y = k;
					}
					if(s[k][0] == i && s[k][1] == j && s[k][4] < p[i][j].second) {
						s[k][0] = 0;
						s[k][1] = 0;
						p[i][j].first -= 1;
					}
				}
			}
		}
	}
}
int solution(vector<vector<pair<int,int>>>& p, vector<vector<int>>& sharks, int fisher, int cnt) {
	fisher += 1;
	for(int i=1; i<p.size(); i++) {
		if(p[i][fisher].first > 0) {
			cnt += p[i][fisher].second;
			p[i][fisher] = {0, 0};
			kill_shark(sharks, i, fisher);
			break;
		}
	}
	for(int i=0; i<sharks.size(); i++) {
		if(sharks[i][0] == 0 || sharks[i][1] == 0) continue;
		move(p, sharks[i]);
	}
	eat(p, sharks);
	if(fisher >= p[1].size()-1) return cnt;
	return solution(p, sharks, fisher, cnt);
}
int main() {
	int R, C, M, r, c, d, s, z;
	cin.tie(0);
	cin >> R >> C >> M;
	vector<vector<pair<int,int>>> p(R+1, vector<pair<int,int>>(C+1, {0,0}));
	vector<vector<int>> sharks(M, vector<int>(5, 0));
	for(int i=0; i<M; i++) {
		cin >> r >> c >> s >> d >> z;
		p[r][c] = {1, z};
		sharks[i][0] = r;
		sharks[i][1] = c;
		sharks[i][2] = s;
		sharks[i][3] = d;
		sharks[i][4] = z;
	}
	printf("%d", solution(p, sharks, 0, 0));
	return 0;
}