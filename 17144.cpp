// https://www.acmicpc.net/problem/17144
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> spread(vector<vector<int>> h) {
	int cnt, v;
	vector<vector<int>> spreaded(h.begin(), h.end());
	for(int i=0; i<h.size(); i++) {
		for(int j=0; j<h[0].size(); j++) {
			if(h[i][j] > 0) {
				cnt = 0;
				v = h[i][j]/5;
				if(i+1 < h.size() && spreaded[i+1][j] != -1) { spreaded[i+1][j] += v; cnt++; }
				if(j+1 < h[0].size() && spreaded[i][j+1] != -1) { spreaded[i][j+1] += v; cnt++; }
				if(i-1 >= 0 && spreaded[i-1][j] != -1) { spreaded[i-1][j] += v; cnt++; }
				if(j-1 >= 0 && spreaded[i][j-1] != -1) { spreaded[i][j-1] += v; cnt++; }
				spreaded[i][j] -= v*cnt;
				if(spreaded[i][j] < 0) spreaded[i][j] = 0;
			}
		}
	}
	return spreaded;
}

void fresh(vector<vector<int>>& h) {
	int air;
	for(int i=0; i<h.size(); i++) {
		if(h[i][0] == -1) {
			air = i;
			break;
		}
	}
	for(int i=air-2; i>=0; i--)
		h[i+1][0] = h[i][0];
	for(int j=1; j<h[0].size(); j++)
		h[0][j-1] = h[0][j];
	for(int i=1; i<=air; i++)
		h[i-1][h[0].size()-1] = h[i][h[0].size()-1];
	for(int j=h[0].size()-2; j>=1; j--) {
		h[air][j+1] = h[air][j];
		h[air][j] = 0;
	}
	air += 1;
	for(int i=air+2; i<h.size(); i++)
		h[i-1][0] = h[i][0];
	for(int j=1; j<h[0].size(); j++)
		h[h.size()-1][j-1] = h[h.size()-1][j];
	for(int i=h.size()-2; i>=air; i--)
		h[i+1][h[0].size()-1] = h[i][h[0].size()-1];
		for(int j=h[0].size()-2; j>=1; j--) {
			h[air][j+1] = h[air][j];
			h[air][j] = 0;
	}
}
int solution(vector<vector<int>> h, int t) {
	int answer=0;
	for(int i=0; i<t; i++) {
		h = spread(h);
		fresh(h);
	}
	for(int j=0; j<h.size(); j++) {
		for(int k=0; k<h[0].size(); k++) {
			if(h[j][k] > 0) answer += h[j][k];
		}
	}
	return answer;
}
int main() {
	int r, c, t;
	cin.tie(0);
	cin >> r >> c>> t;
	vector<vector<int>> house(r, vector<int>(c, 0));
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++)
			cin >> house[i][j];
	}
	cout << solution(house, t);
	return 0;
}