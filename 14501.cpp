#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solution(int* t, int* p, int n) {
	int tmp;
	vector<int> cost(n + 1, 0);
	for(int i=1; i<=n; i++) {
	if(i+t[i]-1 > n) continue;

	}
	cout << cost[n];
	return;
}

int main() {
	int n;
	cin.tie(0);
	cin >> n;
	int* t = new int[n + 1];
	int* p = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	solution(t, p, n);
	delete[] t;
	delete[] p;
	return 0;
}