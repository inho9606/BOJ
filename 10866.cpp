#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int n, x;
	string input;
	deque<int> dq;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> input;
		if(input == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if(input == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if(input == "pop_front") {
			if(dq.empty() == 1) cout << "-1\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if(input == "pop_back") {
			if(dq.empty() == 1) cout << "-1\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if(input == "size") cout << dq.size() << "\n";
		else if(input == "empty") cout << int(dq.empty()) << "\n";
		else if(input == "front") {
			if(dq.empty() == 0) cout << dq.front() << "\n";
			else cout << "-1\n";
		}
		else if(input == "back") {
			if(dq.empty() == 0) cout << dq.back() << "\n";
			else cout << "-1\n";
		}
	}
	return 0;
}