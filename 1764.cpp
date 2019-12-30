// time: O(nLogm)
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
	int n, m;
	set<string> unknown, unseen, both;
	set<string>::iterator ptr;
	string person;
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> person;
		unknown.insert(person);
	}
	for(int i=0; i<m; i++) {
		cin >> person;
		unseen.insert(person);
	}
	for(ptr = unknown.begin(); ptr != unknown.end(); ptr++) {
		if(unseen.count(*ptr) == 1) both.insert(*ptr);
	}
	cout << both.size() << "\n";
	for(ptr = both.begin(); ptr != both.end(); ptr++)
		cout << *ptr << "\n";
	return 0;
}