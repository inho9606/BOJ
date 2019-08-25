#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, k, sum=0;
	stack<int> money;
	cin.tie(0);
	cin >> k;
	for(int i=0; i<k; i++) {
		cin >> n;
		if(n == 0) {
			sum -= money.top();
			money.pop();
		}
		else {
			sum += n;
			money.push(n);
		}
	}
	cout << sum;
	return 0;
}