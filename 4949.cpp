#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string input;
	stack<int> s;
	while(1) {
		while(s.empty() == 0) s.pop();
		getline(cin, input);
		if(input.length() == 1) break;
		for(int i=0; i<input.length(); i++) {
			if(input[i] == '(') s.push(1);
			else if(input[i] == '[') s.push(2);
			else if(input[i] == ')') {
				if(s.empty() == 0 && s.top() == 1) s.pop();
				else {
					s.push(1);
					break;
				}
			}
			else if(input[i] == ']') {
				if(s.empty() == 0 && s.top() == 2) s.pop();
				else {
					s.push(1);
					break;
				}
			}
		}
		if(s.empty() == 1) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}