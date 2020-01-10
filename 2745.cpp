#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(string n, int b) {
	int d=1, answer=0;
	for(int i=n.size()-1; i>=0; i--) {
		if(n[i] >= '0' && n[i] <= '9') answer += (n[i]-48)*d;
		else answer += (n[i]-('A'-10))*d;
		d *= b;
	}
	return answer;
}

int main() {
	string n;
	int b;
	cin >> n >> b;
	printf("%d", solution(n, b));
	return 0;
}