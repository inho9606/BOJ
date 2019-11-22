#include <iostream>
using namespace std;
int result = 0;
	int n, m;
int card[300000];

void check(int before, int pos, int count) {
	if(before > m) return;
	if(count == 3 && before > result) {
		result = before;
		return;
	}
	if(count == 2) {
		for(int i=pos+1; i<n; i++)
			check(before+card[i], i, 3);
	}
	if(count == 1) {
		for(int i=pos+1; i<n-1; i++)
			check(before+card[i], i, 2);
	}
}

int main() {
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> card[i];
	for(int i=0; i<n-2; i++)
		check(card[i], i, 1);
	cout << result;
	return 0;
}