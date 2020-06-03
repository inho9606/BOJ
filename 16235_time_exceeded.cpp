// https://www.acmicpc.net/problem/16235
// Time Exceed
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct tree {
	pair<int,int> location;
	int nutrients=0;
	bool died = 0;
}tree;

void spring(vector<vector<pair<int,int>>>& g, multimap<int,tree>& t) {
	int x, y;
	multimap<int,tree> tmp;
	for(auto ptr=t.begin(); ptr != t.end();) {
		x = ptr->second.location.first;
		y = ptr->second.location.second;
		if(g[x][y].first >= ptr->first && ptr->second.died == 0) {
			ptr->second.nutrients += ptr->first;
			g[x][y].first -= ptr->first;
			tmp.insert({ptr->first+1, ptr->second});
			t.erase(ptr++);
		}
		else if(g[x][y].first < ptr->first && ptr->second.died == 0) {
			ptr->second.died = 1;
			g[x][y].second -= 1;
			ptr++;
		}
	}
	for(auto ptr=tmp.begin(); ptr != tmp.end(); ptr++)
		t.insert({ptr->first, ptr->second});
}
void summer(vector<vector<pair<int,int>>>& g, multimap<int,tree>& t) {
	int x, y;
	for(auto ptr = t.begin(); ptr != t.end();) {
		if(ptr->second.died==1) {
			x = ptr->second.location.first;
			y = ptr->second.location.second;
			g[x][y].first += ptr->second.nutrients/2;
			t.erase(ptr++);
		}
		else ptr++;
	}
}
void fall(vector<vector<pair<int,int>>>& g, multimap<int,tree>& t) {
	int x, y;
	tree nt;
	multimap<int,tree> tmp;
	for(auto ptr = t.begin(); ptr != t.end(); ptr++) {
		if(ptr->first % 5 == 0) {
			x = ptr->second.location.first;
			y = ptr->second.location.second;
			if(x-1 >= 1 && y-1 >= 1) {
				g[x-1][y-1].second += 1;
				nt.location = {x-1,y-1};
				t.insert({1, nt});
			}
			if(x-1 >= 1) {
				g[x-1][y].second += 1;
				nt.location = {x-1,y};
				t.insert({1, nt});
			}
			if(x-1 >= 1 && y+1 < g.size()) {
				g[x-1][y+1].second += 1;
				nt.location = {x-1,y+1};
				t.insert({1, nt});
			}
			if(y-1 >= 1) {
				g[x][y-1].second += 1;
				nt.location = {x,y-1};
				t.insert({1, nt});
			}
			if(x+1 < g.size() && y-1 >= 1) {
				g[x+1][y-1].second += 1;
				nt.location = {x+1,y-1};
				t.insert({1, nt});
			}
			if(x+1 < g.size()) {
				g[x+1][y].second += 1;
				nt.location = {x+1,y};
				t.insert({1, nt});
			}
			if(x+1 < g.size() && y+1 < g.size()) {
				g[x+1][y+1].second += 1;
				nt.location = {x+1,y+1};
				t.insert({1, nt});
			}
			if(y+1 < g.size()) {
				g[x][y+1].second += 1;
				nt.location = {x,y+1};
				t.insert({1, nt});
			}
		}
	}
}
void winter(vector<vector<pair<int,int>>>& g, vector<vector<int>>& a) {
	for(int i=1; i<a.size(); i++) {
		for(int j=1; j<a.size(); j++) {
			g[i][j].first += a[i][j];
		}
	}
}
int solution(vector<vector<pair<int,int>>>& g, vector<vector<int>>& a, multimap<int,tree>& t, int k) {
	for(int i=0; i<k; i++) {
		spring(g, t);
		summer(g, t);
		fall(g, t);
		winter(g, a);
	}
	return t.size();
}
int main() {
	int n, m, k, x, y, z;
	tree tmp;
	cin.tie(0);
	cin >> n >> m >> k;
	vector<vector<pair<int,int>>> g(n+1, vector<pair<int,int>>(n+1, {5, 0}));
	vector<vector<int>> a(n+1, vector<int>(n+1));
	multimap<int,tree> trees;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			cin >> a[i][j];
	}
	for(int i=0; i<m; i++) {
		cin >> x>> y >> z;
		tmp.location = {x,y};
		trees.insert({z, tmp});
		g[x][y].second = 1;
	}
	cout << solution(g, a, trees, k);
	return 0;
}