#include <iostream>
using namespace std;

int main() {
	int n;
	cin.tie(0);
	cin >> n;
	if(n == 1) {
		cout << "1";
		return 0;
	}
	int* f = new int[n+1];
	f[0] = 0; f[1] = 1;
	for(int i=2; i<=n; i++)
		f[i] = f[i-1] + f[i-2];
	cout << f[n];
	delete[] f;
	return 0;
}