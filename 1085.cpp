#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h, n;
	cin >> x >> y >> w >> h;
	n = min(min(x, w-x), min(y, h-y));
	cout << n;
	return 0;
}