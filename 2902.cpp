#include <iostream>
#include <string>
using namespace std;
string solution(string s) {
	string p = "";
	int point = 1;
	for (int i = 0; i < s.length(); i++) {
		if (point == 1) {
			 p += s[i];
			point = 0;
		}
		if (s[i] == '-') point = 1;
	}
	return p;
}

int main() {
	string s;
	cin >> s;
	cout << solution(s) << endl;
	return 0;
}