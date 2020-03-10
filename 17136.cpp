// I. 색종이를 크기별로 하나씩 붙여본다.
// II. 사용한 색종이가 각각 5개 이상이면 탐색을 중단한다.
#include <iostream>
#include <vector>
using namespace std;
int cnt = 0, answer = -1;
int c[5] = { 0,0,0,0,0 };

bool check(vector<vector<int> >& p, int i, int j, int k) {
	for (int y = i; y <= i + k; y++) {
		if (y == 10) return 0;
		for (int x = j; x <= j + k; x++) {
			if (x == 10) return 0;
			if (p[y][x] == 0) return 0;
		}
	}
	return 1;
}
void solution(vector<vector<int> > p) {
	int k, y, x, temp, done = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (p[i][j] == 1) {
				for (k = 4; k >= 0; k--) {
					if (c[k] < 5 && check(p, i, j, k) == 1 && (answer == -1 || cnt + 1 < answer)) {
						done = 0;
						for (y = i; y <= i + k; y++) {
							for (x = j; x <= j + k; x++)
								p[y][x] = 0;
						}
						cnt += 1;
						c[k] += 1;
						temp = cnt;
						solution(p);
						cnt = temp - 1;
						c[k] -= 1;
						for (y = i; y <= i + k; y++) {
							for (x = j; x <= j + k; x++)
								p[y][x] = 1;
						}
					}
				}
				return;
			}
		}
	}
	if (done == 1) {
		if (answer == -1 && cnt >= 0) answer = cnt;
		else if (cnt < answer) answer = cnt;
	}
}
int main() {
	cin.tie(0);
	vector<vector<int> > paper(10, vector<int>(10));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cin >> paper[i][j];
	}
	solution(paper);
	printf("%d", answer);
	return 0;
}