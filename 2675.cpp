#include <iostream>
#include <string>
using namespace std;
string solution(int r, string s) {
	string p = "";
	for (int j = 0; j < s.length(); j++) {
		for (int k = 0; k < r; k++)
			p += s[j];
	}
	return p;
}

int main() {
	int t, r;
	string s;
	cin >> t;
	cin.ignore(256,'\n');
	for(int i=0; i<t; i++) {
	cin >> r;
		cin >> s;
	cout << solution(r, s) << endl;
	}
	return 0;
}