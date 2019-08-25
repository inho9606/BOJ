#include<iostream>
#include <cmath>
using namespace std;
#define MAX = 100000;
bool c[MAX + 1];
int main() {
	c[0] = c[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (c[i] == false) {
			for (int j = i * i; j <= MAX; j = j + i)
				c[j] = true;
		}
	}
	int t, n, count, j;
	cin.tie(0);
	cin >> t;
	for(int i=0; i<t; i++) {
		j=2;
		count=0;
		cin >> n;
		while(j<MAX+1) {
		if(c[j] == true) {
			j++;
			continue;
		}
			if(c[j] == false && n%j == 0) {
				count++;
				n/=j;
				continue;
			}
			if (c[j] == false && n%j != 0) {
				if(count > 0)
					cout << j << " " << count << "\n";
				count = 0;
				j += 1;
			}
			if(n==1) break;
		}

	}
	return 0;
}