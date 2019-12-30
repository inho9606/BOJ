// time: O(n)
#include <iostream>
using namespace std;

int main() {
	int numbers[100];
	int n, v, cnt=0;
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> numbers[i];
	cin >> v;
	for(int i=0; i<n; i++) {
		if(numbers[i] == v) cnt++;
	}
	cout << cnt;
	return 0;
}