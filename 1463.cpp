#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, t1, t2, t3;
	cin.tie(0);
	cin >> n;
	int* f = new int[n+1];
	for(int i=0; i<=n; i++)
		f[i] = 0;
	f[0] = 0;
	f[1] = 0;
	f[2] = 1;
	f[3] = 1;
	for(int i=4; i<=n; i++) {
		t1 = 2100000000;
		t2 = 2100000000;
		t3 = 2100000000;
		if(i % 3 == 0) t1 = f[i/3];
		if(i % 2 == 0) t2 = f[i/2];
		t3 = f[i-1];
		f[i] = min(min(t1, t2), t3) +1;
	}
	cout << f[n];
	delete[] f;
	return 0;
}

