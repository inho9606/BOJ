// time: O(logn)
// �� ���� a b�� ���Ͽ�, a>b�̰� a%b=r�̸� gcd(a,b) = gcd(b,r)�� ����.
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