#include <iostream>
using namespace std;
bool visit[1001];
int n, cnt = 0;
int numbers[4] = {1,5,10,50};

void solution(int c, int k, int sum) {
	if(c == n) {
		if(visit[sum] == 0) {
			visit[sum] = 1;
			cnt += 1;
		}
		return;
	}
	for(int i=k; i<4; i++)
		solution(c+1, i, sum+numbers[i]);
}

int main() {
	cin.tie(0);
	cin >> n;
	solution(0, 0, 0);
	cout << cnt;
	return 0;
}