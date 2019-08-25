#include<iostream>
#include <cmath>
#include<iostream>
#include <cmath>
#define  MAX = 10000;
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
	int t, n;
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for(int i=n/2; i>0; i--)
			if (c[i] == false && c[n - i] == false) {
				cout << i << " " << n - i << "\n";
				break;
			}
	}
	return 0;
}


using namespace std;
const int MAX = 10000;
bool c[MAX + 1];
int main() {
	c[0] = c[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (c[i] == false) {
			for (int j = i * i; j <= MAX; j = j + i)
				c[j] = true;
		}
	}
	int t, n;
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for(int i=n/2; i>0; i--)
			if (c[i] == false && c[n - i] == false) {
				cout << i << " " << n - i << "\n";
				break;
			}
	}
	return 0;
}