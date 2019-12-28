#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> s;
	int n, x;
	set<int>::iterator ptr;
	cin.tie(0);
	cout.tie(0);
	for(int i=0; i<n; i++) {
		cin >> x;
		s.insert(x);
	}
	for(ptr = s.begin(); ptr != s.end(); ptr++)
		cout << *ptr << " ";
	return 0;
}