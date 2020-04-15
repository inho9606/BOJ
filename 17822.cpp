// https://www.acmicpc.net/problem/17822
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(vector<vector<int>>& p) {
	int tmp, changed, final = 0, x, y;
	queue<pair<int,int>> q;
	for(int i=1; i<p.size(); i++) {
		for(int j=0; j<p[i].size(); j++) {
			if(p[i][j] != 0) {
				q.push({i,j});
				tmp = p[i][j];
				changed = 0;
				while(q.empty() == 0) {
					y = q.front().first;
					x = q.front().second;
					q.pop();
					if(y>1 && p[y-1][x] == tmp) {
						q.push({y-1,x});
						p[y-1][x] = 0;
						changed+=1;
					}
					if(y < p.size()-1 && p[y+1][x] == tmp) {
						q.push({y+1,x});
						p[y+1][x] = 0;
						changed+=1;
					}
					if(x==0 && p[y][p[y].size()-1] == tmp) {
						q.push({y, p[y].size()-1});
						p[y][p[y].size()-1] = 0;
						changed +=1 ;
					}
					if(x>0 && p[y][x-1] == tmp) {
						q.push({y,x-1});
						p[y][x-1] = 0;
						changed+=1;
					}
					if(x < p[y].size()-1 && p[y][x+1] == tmp) {
						q.push({y,x+1});
						p[y][x+1] = 0;
						changed+=1;
					}
					if(x == p[y].size()-1 && p[y][0] == tmp) {
						q.push({y,0});
						p[y][0] = 0;
						changed += 1;
					}
				}
				if(changed > 0) { p[i][j] = 0; final = 1; }
			}
		}
	}
	if(final == 1) return 1;
	return 0;
}
void solution(vector<vector<int> >& p, int x, int d, int k) {
	int tmp;
	for(int i=x; i<p.size(); i+=x) {
		if(d == 0) {
			for(int cnt=0; cnt<k; cnt++) {
				tmp = p[i][p[i].size()-1];
				for(int j=p[i].size()-1; j>0; j--)
					p[i][j] = p[i][j-1];
				p[i][0] = tmp;
			}
		}
		else if(d==1) {
			for(int cnt=0; cnt<k; cnt++) {
				tmp = p[i][0];
				for(int j=0; j<p[i].size()-1; j++)
					p[i][j] = p[i][j+1];
				p[i][p[i].size()-1] = tmp;
			}
		}
	}
}

int main() {
	cin.tie(0);
	int n, m, t, x, d, k, sum, valid;
	double avg;
	cin >> n >> m >> t;
	vector<vector<int> > plane(n+1, vector<int>(m, 0));
	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++)
			cin >> plane[i][j];
	}
	for(int i=0; i<t; i++) {
		cin >> x >> d >> k;
		solution(plane, x, d, k);
		if(check(plane) == 0) {
			double avg;
			valid=0;
			sum = 0;
			for(int ii=1; ii<=n; ii++) {
				for(int j=0; j<m; j++) {
					if(plane[ii][j] != 0) { sum += plane[ii][j]; valid+=1; }
				}
			}
			avg = (double)sum/valid;
			for(int ii=1; ii<=n; ii++) {
				for(int j=0; j<m; j++) {
					if(plane[ii][j] != 0 && (double)plane[ii][j] > avg) plane[ii][j] -= 1;
					else if(plane[ii][j] != 0 && (double)plane[ii][j] < avg) plane[ii][j] += 1;
				}
			}
		}
	}
	sum = 0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++) {
			sum += plane[i][j];
		}
	}
	printf("%d\n", sum);
	return 0;
}