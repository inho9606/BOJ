#include <iostream>
using namespace std;
int n, lion[100000][3];

int main() {
	lion[0][0] = 1;
	lion[0][1] = 1;
	lion[0][2] = 1;
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		lion[i][0] = (lion[i - 1][1] + lion[i - 1][2]) % 9901;
		lion[i][1] = (lion[i - 1][0] + lion[i - 1][2]) % 9901;
		lion[i][2] = (lion[i - 1][0] + lion[i - 1][1] + lion[i - 1][2]) % 9901;
	}
	cout << (lion[n-1][0] + lion[n-1][1] + lion[n-1][2]) % 9901;
	return 0;
}