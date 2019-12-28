// time : O(nx)
// space: O(n)

#include <iostream>
#include <list>
using namespace std;
list<pair<int, int> > bloon;

int main() {
	cin.tie(0);
	cout.tie(0);
	int n, x;
	list<pair<int, int> >::iterator ptr;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		bloon.push_back({ x, i });
	}
	for (ptr = bloon.begin(); bloon.size() != 0; ) {
		cout << (*ptr).second << " ";
		x = (*ptr).first;
		ptr = bloon.erase(ptr);
		if(bloon.empty() == 1) break;
		if (ptr == bloon.end()) ptr = bloon.begin();
		if (x < 0) {
			for (int i = x; i < 0; i++) {
				if (ptr == bloon.begin()) ptr = bloon.end();
				ptr--;
			}
		}
		else {
			for (int i = 0; i < x - 1; i++) {
				if (++ptr == bloon.end()) ptr = bloon.begin();
			}
		}
	}
	return 0;
}