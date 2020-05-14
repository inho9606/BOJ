// https://www.acmicpc.net/problem/14890
// l이 1이면 어디선가 무한루프 걸림..

#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;

bool check_row(vector<vector<int>>& m, vector<vector<bool>>& s, int l, int y, int x) {
	if(l==1) return 1;
	for (int i = x + 1; i < x + l; i++)
		if (i >= m.size() || s[y][i] == 1 || m[y][i] != m[y][i - 1]) return 0;
	return 1;
}
void update_row(vector<vector<int>>& m, vector<vector<bool>>& s, int y, int x, int l) {
	for (int i = x; i < x + l; i++) {
		m[y][i] += 1;
		s[y][i] = 1;
	}
}
void undo_row(vector<vector<int>>& m, vector<vector<bool>>& s, int y, int x, int l) {
	for (int i = x; i < x + l; i++) {
		m[y][i] -= 1;
		s[y][i] = 0;
	}
}
bool check_coldown(vector<vector<int>>& m, vector<vector<bool>>& s, int l, int y, int x) {
	if(l==1) return 1;
	for (int i = y + 1; i < y + l; i++)
		if (i >= m.size() || s[i][x] == 1 || m[i][x] != m[i - 1][x]) return 0;
	return 1;
}
void update_coldown(vector<vector<int>>& m, vector<vector<bool>>& s, int y, int x, int l) {
	for (int i = y; i < y + l; i++) {
		m[i][x] += 1;
		s[i][x] = 1;
	}
}
void undo_coldown(vector<vector<int>>& m, vector<vector<bool>>& s, int y, int x, int l) {
	for (int i = y; i < y + l; i++) {
		m[i][x] -= 1;
		s[i][x] = 0;
	}
}
bool check_colup(vector<vector<int>>& m, vector<vector<bool>>& s, int l, int y, int x) {
	if(l==1) return 1;
	for (int i = y - 1; i > y - l; i--)
		if (i < 0 || s[i][x] == 1 || m[i][x] != m[i + 1][x]) return 0;
	return 1;
}
void update_colup(vector<vector<int>>& m, vector<vector<bool>>& s, int y, int x, int l) {
	for (int i = y; i > y - l; i--) {
		m[i][x] += 1;
		s[i][x] = 1;
	}
}
void undo_colup(vector<vector<int>>& m, vector<vector<bool>>& s, int y, int x, int l) {
	for (int i = y; i > y - l; i--) {
		m[i][x] -= 1;
		s[i][x] = 0;
	}
}

void solution(vector<vector<int>> m, vector<vector<bool>> s, int l, int y, int x) {
	int ways = 0, h, done = 1;
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			if (j == 0) h = m[i][j];
			if (h - m[i][j] <= -2 || h - m[i][j] >= 2) break;
			else if (m[i][j] > h) h = m[i][j];
			if (j == m.size() - 1) {
				for (int t = 0; t < m.size(); t++) {
					if (h - m[i][j] >= 2) break;
					if(t == m.size()-1) {
				for (int k = 0; k < m.size(); k++) {
					if (h - m[i][k] == 1) {
						if ((i >= y || (i == y && k >= x)) && check_row(m, s, l, i, k)) { done = 0; update_row(m, s, i, k, l); solution(m, s, l, i, k); undo_row(m, s, i, k, l); }
						if ((i >= y || (i == y && k >= x)) && check_coldown(m, s, l, i, k)) { done = 0; update_coldown(m, s, i, k, l); solution(m, s, l, i, k); undo_coldown(m, s, i, k, l); }
						if ((i >= y || (i == y && k >= x)) && check_colup(m, s, l, i, k)) { done = 0; update_colup(m, s, i, k, l); solution(m, s, l, i, k); undo_colup(m, s, i, k, l); }
					}
				}
			}
		}
	}
	}
	}
	if (done == 1) {
		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < m.size(); j++) {
				if (j > 0 && m[i][j - 1] != m[i][j]) break;
				if (j == m.size() - 1) ways += 1;
			}
		}
		if (ways > cnt) cnt = ways;
	}
}
int main() {
	int n, l, answer=0;
	cin.tie(0);
	cin >> n >> l;
	vector<vector<int>> m(n, vector<int>(n));
	vector<vector<int>> mm(n, vector<int>(n));
	vector<vector<bool>> s(n, vector<bool>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			mm[j][i] = m[i][j];
		}
	}
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m.size(); j++) {
			if(j>0 && m[i][j] != m[i][j-1]) break;
			if(j==m.size()-1) answer-=1;
		}
	}
	solution(m, s, l, 0, 0);
	answer += cnt;
	cnt = 0;
	solution(mm, s, l, 0, 0);
	answer += cnt;
	printf("%d", answer);
	return 0;
}