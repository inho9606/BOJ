#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int t;
	string input;
	stack<int> ps;
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		while (ps.empty() == 0) ps.pop();
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			if (input[j] == '(') ps.push(1);
			else {
				if (ps.empty() == 1) {
					ps.push(0);
					break;
				}
				else ps.pop();
			}
		}
		if (ps.empty() == 0) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}