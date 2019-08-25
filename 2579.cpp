#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin.tie(0);
	cin >> n; // input the number of steps
	int* s = new int[n + 1]; // to store scores on each step
	s[0] = 0; // The start point
	for (int i = 1; i <= n; i++)
		cin >> s[i]; // initialize scores on each step
	int* scores = new int[n + 1]; // to store sum of scores from the bottom to nth step
	scores[0] = 0; // the start point
	scores[1] = s[1]; // the first step
	scores[2] = s[1] + s[2]; // scores from the start point to the second step
	for (int i = 3; i <= n; i++)
		scores[i] = max(scores[i - 3] + s[i - 1] + s[i], scores[i - 2] + s[i]); // decide which is bigger between one coming from the last step and another coming  from the last second step
			cout << scores[n]; // return sum of the highest scores from the start point to nth step
		delete[] scores;
		delete[] s;
	return 0;
}