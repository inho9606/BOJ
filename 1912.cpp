#include <iostream>
using namespace std;
int s[100000];

int solution(int n) {
	int answer= s[0];
	int so_far=s[0];
	for(int i=1; i<n; i++) {
		if(so_far + s[i] > s[i]) so_far += s[i];
		else so_far = s[i];
		if(so_far > answer) answer = so_far;
	}
	return answer;
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> s[i];
	cout << solution(n);
	return 0;
}