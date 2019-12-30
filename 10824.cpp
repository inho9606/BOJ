#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b, c, d;
	unsigned long long n=0, m=0;
	cin.tie(0);
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	for(int i=0; i<a.length(); i++) {
		n *= 10;
		n += a[i] - 48;
	}
	for(int i=0; i<c.length(); i++) {
		m *= 10;
		m += c[i] - 48;
	}
	cout << n + m;
	return 0;
}