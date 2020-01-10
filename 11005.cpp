#include <iostream>
#include <vector>
using namespace std;

void solution(int n, int b) {
	vector<char> nums;
	for(int i=n; i>0; i/=b) {
		if(i%b < 10) nums.push_back((i%b)+48);
		else nums.push_back((i%b)+('A'-10));
	}
	for(int i=nums.size()-1; i>=0; i--)
		cout << nums[i];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	int n, b;
	cin >> n >> b;
	solution(n, b);
	return 0;
}