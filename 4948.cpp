#include<iostream>
#define MAX = 123456 * 2
using namespace std;
bool c[MAX + 1];
int main() {
	c[0] = c[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (c[i] == false) {
			for (int j = i * i; j <= MAX; j = j + i)
				c[j] = true;
		}
	}
	int n, count;
	cin.tie(0);
	while (1) {
		cin >> n;
		if (n == 0) break;
		count = 0;
		for (int i = n + 1; i <= 2 * n; i++)
			if (c[i] == false) count++;
		cout << count << "\n";
	}
	return 0;
}