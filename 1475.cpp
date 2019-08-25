#include <iostream>
#include <cstdio>
using namespace std;

int solution(string n) {
	int number = 0;
	int package[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < n.length(); i++)
		package[n[i]-48] += 1;
	package[6] = (package[6] + package[9]) / 2 + (package[6] + package[9]) % 2;
	package[9] = 0;
	for (int i = 0; i < 10; i++)
		if (package[i] > number) number = package[i];
	return number;
}

int main() {
	string n;
	cin >> n;
	cout << solution(n);
	return 0;
}

