// time: O(nm)
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	string text;
	char cmd, x;
	int n, m;
	list<char> editor;
	list<char>::iterator c, temp;
	cin >> text;
	n = text.length();
	for(int i=0; i<n; i++)
		editor.push_back(text[i]);
	cin >> m;
	c = editor.end();
	for(int i=0; i<m; i++) {
		cin >> cmd;
		if(cmd == 'L') {
			if(c == editor.begin()) continue;
			c--;
		}
		else if(cmd == 'D') {
			if(c == editor.end()) continue;
			c++;
		}
		else if(cmd == 'B') {
			if(c == editor.begin()) continue;
			temp = c;
			editor.erase(--temp);
		}
		else if(cmd == 'P') {
			cin >> x;
			editor.insert(c, x);
		}
	}
	for(c = editor.begin(); c != editor.end(); c++)
		cout << *c;
	return 0;
}