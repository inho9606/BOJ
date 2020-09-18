#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist(vector<vector<int>>& g, vector<int> dest, int i, int j) {
	int r, c, n=g.size(), d;
	queue<pair<pair<int,int>,int>> q;
	vector<vector<bool>> v(n, vector<bool>(n, 0));
	q.push({{i,j},0});
	v[i][j] = 1;
	while(q.empty() == 0) {
		r = q.front().first.first;
		c = q.front().first.second;
		d = q.front().second;
		q.pop();
		if(r == dest[0] && c == dest[1]) break;
		if(r+1 < n && g[r+1][c] == 0 && v[r+1][c] == 0) {
			v[r+1][c] = 1;
			q.push({{r+1,c},d+1});
		}
		if(c+1 < n && g[r][c+1] == 0 && v[r][c+1] == 0) {
			v[r][c+1] = 1;
			q.push({{r,c+1},d+1});
		}
		if(r-1 > 0 && g[r-1][c] == 0 && v[r-1][c] == 0) {
			v[r-1][c] = 1;
			q.push({{r-1,c},d+1});
		}
		if(c-1 > 0 && g[r][c-1] == 0 && v[r][c-1] == 0) {
			v[r][c-1] = 1;
			q.push({{r,c-1},d+1});
		}
	}
	if(r != dest[0] || c != dest[1]) return 2110000000;
	return d;
}
int solution(vector<vector<int>>& g, vector<vector<int>>& sources, vector<vector<int>>& dests, int r, int c, int l) {
	int answer=l, d, p, t;
	while(sources.size() > 0) {
		d = 2100000000;
		p=-1;
		for(int i=0; i<sources.size(); i++) {
			t = dist(g, sources[i], r, c);
			if(t < d) {
				d = t;
				p = i; 
			}
			else if(t==d) {
				if(sources[i][0] < sources[p][0]) p=i;
				else if(sources[i][0] == sources[p][0] && sources[i][1] < sources[p][1]) p=i;
			}
		}
		answer -= d;
		if(answer<0) return -1;
		r = sources[p][0];
		c = sources[p][1];
		t = dist(g, dests[p], r, c);
		answer -= t;
		if(answer<0) return -1;
		answer += 2*t;
		r = dests[p][0];
		c = dests[p][1];
		sources.erase(sources.begin()+p);
		dests.erase(dests.begin()+p);
	}
	return answer;
}
int main() {
	int n, m, l, r, c;
	cin.tie(0);
	cin >> n >> m >> l;
	vector<vector<int>> sources(m, vector<int>(2, 0)), dests(m, vector<int>(2, 0));
	vector<vector<int>> g(n+1, vector<int>(n+1));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			cin >> g[i][j];
	}
	cin >> r >> c;
	for(int i=0; i<m; i++) {
		for(int j=0; j<2; j++)
			cin >> sources[i][j];
		for(int j=0; j<2; j++)
			cin >> dests[i][j];
	}
	cout << solution(g, sources, dests, r, c, l);
	return 0;
}