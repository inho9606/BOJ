#include <iostream>
#include <string>
using namespace std;
string solution(string s) {
	string p = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		p += s[i];
	}
	return p;
}

int main() {
	string s;
	string q = "END";
	while (1) {
		getline(cin, s);
		if (s != "END")
			cout << solution(s) << endl;
		else break;
	}
	return 0;
}