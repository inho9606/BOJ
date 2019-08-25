#include <iostream>
using namespace std;

int main() {
	int n;
	cin.tie(0);
	cin >> n;
	int* f = new int[n+1];
	f[1] = 1;
	f[2] = 3;
	for(int i=3; i<=n; i++)
		f[i] = (f[i-1]+(2*f[i-2])) % 10007;
	cout << f[n];
	delete[] f;
	return 0;
}