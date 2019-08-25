#include <iostream>
using namespace std;

int main() {
	long long p[101];
	p[0] = 0;
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	p[4] = 2;
	p[5] = 2;
	for (int i = 6; i <= 100; i++)
		p[i] = p[i - 1] + p[i - 5];
	int t, n;
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << p[n] << "\n";
	}
	return 0;
}