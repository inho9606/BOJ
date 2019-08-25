#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n) {
	int i, check, count = 0;
	for(i=666; count!=n; i++) {
		check = 0;
		for(int num=i; num>0; num/=10)
			if(num%10 == 6) check++;
			else if(check<3) check=0;
		if(check>=3) count++;
	}
	return i-1;
}
int main() {
		int n;
		cin >> n;
		cout << solution(n);
	return 0;
}