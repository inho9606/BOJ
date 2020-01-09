// time: O(logn)
// 두 정수 a b에 대하여, a>b이고 a%b=r이면 gcd(a,b) = gcd(b,r)과 같다.
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if(a%b==0) return b;
	return gcd(b, a%b);
}

int main() {
	int a, b;
	cin >> a >> b;
	int answer;
	if(a>b) answer = gcd(a,b);
	else answer = gcd(b,a);
	cout << answer << " " << a*b/answer;
	return 0;
}