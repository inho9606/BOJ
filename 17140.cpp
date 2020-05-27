// https://www.acmicpc.net/problem/17140
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int,int> find_target(unordered_map<int,int>& m) {
	if(m.empty() == 1) return {-1,-1};
	int a=200, b=200;
	for(auto ptr=m.begin(); ptr != m.end(); ptr++) {
		if(ptr->second < b) {
			a = ptr->first;
			b = ptr->second;
		}
		else if(ptr->second == b && ptr->first < a)
			a = ptr->first;
	}
	m.erase(a);
	return {a, b};
}


void R_operation(vector<vector<int>>& a) {
	int n=0;
	pair<int,int> m;
	unordered_map<int,int> elements;
	for(int i=1; i<a.size(); i++) {
		elements.clear();
		for(int j=1; j<a[i].size(); j++) {
			if(a[i][j] == 0) continue;
			elements[a[i][j]] += 1;
		}
		m = find_target(elements);
		for(int j=1; j<a[i].size(); j++) {
			if(m.first == -1) a[i][j] = 0;
			else if(m.first == 0) {
				a[i][j] = m.second;
				m = find_target(elements);
			}
			else {
				a[i][j] = m.first;
				m.first = 0;
			}
		}
		while(m.first!=-1) {
			if(m.first == 0) {
				a[i].push_back(m.second);
				m = find_target(elements);
			}
			else {
				a[i].push_back(m.first);
				m.first = 0;
			}
		}
		if(a[i].size() > n) n = a[i].size();
	}
	for(int i=1; i<a.size(); i++) {
		if(a[i].size() < n) a[i].resize(n, 0);
	}
}
int solution(vector<vector<int>>& a, int r, int c, int k, int cnt) {
	if(cnt > 100) return -1;
	if(r < a.size() && c < a[1].size() && a[r][c] == k) return cnt;
	if(a.size() >= a[1].size()) R_operation(a);
	else {
		vector<vector<int>> tmp(a[1].size(), vector<int>(a.size()));
		for(int i=1; i<a.size(); i++) {
			for(int j=1; j<a[i].size(); j++)
				tmp[j][i] = a[i][j];
		}
		R_operation(tmp);
		a.clear();
		a.resize(tmp[1].size(), vector<int>(tmp.size()));
		for(int i=1; i<tmp.size(); i++) {
			for(int j=1; j<tmp[1].size(); j++)
				a[j][i] = tmp[i][j];
		}
	}
	if(a.size() > 101) a.resize(101, vector<int>(101));
	for(int i=1; i<a.size(); i++) {
		for(int j=1; j<a[i].size(); j++) {
			if(a[i].size() > 101) a[i].resize(101);
		}
	}
	return solution(a, r, c, k, cnt+1);
}

int main() {
	cin.tie(0);
	int r, c, k;
	vector<vector<int>> a(4, vector<int>(4));
	cin >> r >> c >> k;
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++)
			cin >> a[i][j];
	}
	printf("%d", solution(a, r, c, k, 0));
	return 0;
}