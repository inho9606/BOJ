// time: O(nLogn+n)
// n = the length of input word
#include <iostream>
#include <vector>
#include <string>
	#include <algorithm>
using namespace std;

int main() {
	string word;
	vector<string> head;
	cin.tie(0);
	cout.tie(0);
	cin >> word;
	for(int i=0; i<word.length(); i++)
		head.push_back(word.substr(i));
	sort(head.begin(), head.end());
	for(int i=0; i<head.size(); i++)
		cout << head[i] << "\n";
	return 0;
}