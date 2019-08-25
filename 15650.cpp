#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;
int check[10] = {0,0,0,0,0,0,0,0,0,0};
int start = 1;
void solution(int count, int n, int m) {
	if (count == m) {
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << "\n";
		check[nums.back()] = 0;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if(check[i] == 1) continue;
		nums.push_back(i);
		check[i] = 1;
		solution(count + 1, n, m);
		nums.pop_back();
//		check[i] = 0;
	}
}

int main() {
	int n, m;
	cin.tie(0);
	cin >> n >> m;
	solution(0, n, m);
	return 0;
}