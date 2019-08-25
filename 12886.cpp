#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
bool check[1500][1500];
int answer = 0;

void solution(int n, int a, int b) {
	int x, y;
	queue<pair<int, int> > q;
	q.push({ a, b });
	check[a][b] = 1;
	while (q.empty() == 0) {
		x = q.front().first;
		y = q.front().second;
		if (x == y && x == n - x - y && y == n - x - y) {
			answer = 1;
			break;
		}
		if (max(x, y) - min(x, y) > 0 && check[min(x, y) * 2][max(x, y) - min(x, y)] == 0) {
			q.push({ min(x,y) * 2, max(x,y) - min(x,y) });
				check[min(x, y) * 2][max(x, y) - min(x, y)] = 1;
		}
		if (max(x, n - x - y) - min(x, n - x - y) > 0 && check[min(x, n - x - y) * 2][max(x, n - x - y) - min(x, n - x - y)] == 0) {
			q.push({ min(x,n - x - y) * 2, max(x,n - x - y) - min(x,n - x - y) });
				check[min(x, n - x - y) * 2][max(x, n - x - y) - min(x, n - x - y)] = 1;
		}
		if (max(y, n - x - y) - min(y, n - x - y) > 0 && check[min(y, n - x - y) * 2][max(y, n - x - y) - min(y, n - x - y)] == 0) {
			q.push({ min(y,n - x - y) * 2, max(y,n - x - y) - min(y,n - x - y) });
				check[min(y, n - x - y) * 2][max(y, n - x - y) - min(y, n - x - y)] = 1;
		}
		q.pop();
	}
}

int main() {
	int a, b, c, n;
		cin.tie(0);
		cin >> a >> b >> c;
	n = a + b + c;
	if (n % 3 == 0) solution(n, a, b);
	cout << answer;
	return 0;
}