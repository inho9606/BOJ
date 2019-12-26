#include <iostream>
#include <math.h>
using namespace std;

int solution(char* x) {
	int size=0, answer=0;
	for(int i=0; x[i]!='\0'; i++) size += 1;
	if(x[0] != '0') {
		for(int i=size-1; i>=0; i--)
			answer += (x[i]-48)* pow(10, size-i-1);
	}
	else{
		if(x[1] == 'x') {
			for(int i=size-1; i>=2; i--) {
				if(x[i] >= '0' && x[i] <= '9')
					answer += (x[i]-48)* pow(16, size-i-1);
				else
					answer += (x[i]-87)* pow(16, size-i-1);
			}
		}
		else {
		for(int i=size-1; i>=0; i--)
			answer += (x[i]-48)* pow(8, size-i-1);
		}
	}
	return answer;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	char x[10];
	cin >> x;
	cout << solution(x);
	return 0;
}