#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool comp(const string& s1, const string& s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	return s1.size() < s2.size();
}

int main() {
	int n;
	string temp;
	cin.tie(0);
	cin >> n;
	string* words = new string[n];
	for (int i = 0; i < n; i++)
		cin >> words[i];
	sort(words, words + n, comp);
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << words[i] << "\n";
			break;
		}
		if (words[i] == words[i + 1]) continue;
		cout << words[i] << "\n";
	}
	delete[] words;
	return 0;
}