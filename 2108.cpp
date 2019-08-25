#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int avg(int* numbers, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += numbers[i];
	if (sum / n >= 0) return int(sum / n + 0.5);
	else return int(sum / n - 0.5);
}

int center(int* numbers, int n) {
	return numbers[n / 2];
}

int freq(int* numbers, int n) {
	int count[8001];
	int temp = 0;
	for (int i = 0; i < 8001; i++)
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[numbers[i] + 4000] += 1;
	for (int i = 0; i < 8001; i++)
		if (count[i] > temp) temp = count[i];
	vector<int> m;
	for (int i = 0; i < 8001; i++)
		if (count[i] == temp)
			m.push_back(i - 4000);
	if (m.size() <= 1) return m[0];
	else return m[1];
}

int range(int* numbers, int n) {
	return numbers[n - 1] - numbers[0];
}

int main() {
	cin.tie(0);
	int n;
	cin >> n;
	int* numbers = new int[n];
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	cout << avg(numbers, n) << "\n";
	sort(numbers, numbers + n);
	cout << center(numbers, n) << "\n";
	cout << freq(numbers, n) << "\n";
	cout << range(numbers, n) << "\n";
	delete[] numbers;
	return 0;
}