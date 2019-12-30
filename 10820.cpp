#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence;
	int lower=0, upper=0, number=0, sp=0;
	cin.tie(0);
	while(1) {
	lower = 0; upper = 0; number = 0; sp = 0;
		cin.clear();
		getline(cin, sentence);
		if(sentence.length() == 0) break;
		for(int i=0; i<sentence.length(); i++) {
			if(sentence[i] >= 'a' && sentence[i] <= 'z') lower++;
			else if(sentence[i] >= 'A' && sentence[i] <= 'Z') upper++;
			else if(sentence[i] >= '0' && sentence[i] <= '9') number++;
			else if(sentence[i] == ' ') sp++;
		}
	cout << lower << " " << upper << " " << number << " " << sp << "\n";
	}
	return 0;
}