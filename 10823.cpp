#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t;
	int n=0, sum=0;
	cin.tie(0);
	while(1) {
		cin.clear();
		getline(cin, t);
		if(t.length() == 0) break;
		s += t;
	}
	for(int i=0; s[i] != '\0'; i++) {
		if(s[i] == ',') { sum += n; n=0; }
		else {
			n*=10;
			n += s[i] - 48;
		}
	}
	sum += n;
	printf("%d", sum);
	return 0;
}