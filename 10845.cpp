#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int n, t;
	queue<int> q;
	string input;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			cin >> t;
			q.push(t);
		}
		else if (input == "pop") {
			if (q.empty() == 1) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (input == "size") cout << q.size() << "\n";
		else if (input == "empty") cout << int(q.empty()) << "\n";
		else if (input == "front") {
			if (q.empty() == 1) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (input == "back") {
			if (q.empty() == 1) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
	return 0;
}