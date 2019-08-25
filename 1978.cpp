#include <iostream>
using namespace std;

int main() {
	int prime, n, x, count = 0;
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		prime = 0;
		cin >> x;
		if (x == 1) continue;
		for (int j = 2; j <= x / 2; j++) {
			if (x % j == 0) {
				prime = 1;
				break;
			}
		}
		if (prime == 1) continue;
		count++;
	}
	cout << count;
	return 0;
}