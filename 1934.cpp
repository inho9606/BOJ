// time: O(logn)
// �� ���� a b�� ���Ͽ�, a>b�̰� a%b=r�̸� gcd(a,b) = gcd(b,r)�� ����.
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if(a%b==0) return b;
	return gcd(b, a%b);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	int a, b, t, answer;
	cin >> t;
	for(int i=0; i<t; i++) {
	cin >> a >> b;
	if(a>b) answer = gcd(a,b);
	else answer = gcd(b,a);
	cout << a*b/answer << "\n";
	}
	return 0;
}