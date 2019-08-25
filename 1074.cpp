#include <iostream>
using namespace std;
int r, c, cnt = 0;
int found = 0;
int solution(int size, int i, int j) {
	if (size == 2) {
		if (i == r && j == c) return 1;
		cnt++;
		if (i == r && j + 1 == c) return 1;
		cnt++;
		if (i + 1 == r && j == c) return 1;
		cnt++;
		if (i + 1 == r && j + 1 == c) return 1;		
		cnt++;
		return 0;
	}
	if (found == 0) found = solution(size / 2, i, j);
	if (found == 0) found = solution(size / 2, i, j + size / 2);
	if (found == 0) found = solution(size / 2, i + size / 2, j);
	if (found == 0) found = solution(size / 2, i+size/2, j+size/2);
}
int main() {
	int n, size=1;
	//cin >> n >> r >> c;
	scanf("%d%d%d", &n, &r, &c);
	for (int i = 1; i <= n; i++)
		size *= 2;
	solution(size, 0, 0);
	//cout << cnt;
	printf("%d", cnt);
	return 0;
}