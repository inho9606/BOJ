#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n, number;
	stack<int> s;
	string command;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "push") cin >> number;
		if (command == "push") s.push(number);
		else if (command == "size")
			cout << s.size() << "\n";
		else if (command == "empty")
			if (s.empty() == 1) cout << "1\n";
			else cout << "0\n";
		else if (command == "top") {
			if (s.empty() == 0)
				cout << s.top() << "\n";
			else
				cout << "-1\n";
		}
		else if (command == "pop") {
			if (s.empty() == 0) {
				cout << s.top() << "\n";
				s.pop();
			}
			else
				cout << "-1\n";
		}
	}
	return 0;
}