// time: O(logn)
// �� ���� a b�� ���Ͽ�, a>b�̰� a%b=r�̸� gcd(a,b) = gcd(b,r)�� ����.
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	int t, n;
	long long answer;
	cin >> t;
	for (int i = 0; i < t; i++) {
		answer = 0;
		cin >> n;
		int* nums = new int[n];
		for (int j = 0; j < n; j++)
			cin >> nums[j];
		sort(nums, nums+n);
		for (int j = n-1; j > 0; j--) {
			for (int k = j - 1; k >= 0; k--)
				answer += gcd(nums[j], nums[k]);
		}
		cout << answer << "\n";
		delete[] nums;
	}
	return 0;
}