#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t, n, target, c, count;
	queue<pair<int, int> > q;
	priority_queue<int> printer;
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		while (q.empty() == 0) q.pop();
		while (printer.empty() == 0) printer.pop();
		cin >> n >> target;
		for (int j = 0; j < n; j++) {
			cin >> c;
			q.push({ c,j });
			printer.push(c);
		}
		for (int count = 1; count <= n; count++) {
			while (printer.top() != q.front().first) {
				q.push({ q.front().first, q.front().second });
				q.pop();
			}
			if (target == q.front().second) {
				cout << count << "\n";
				break;
			}
			q.pop();
			printer.pop();
		}
	}
	return 0;
}