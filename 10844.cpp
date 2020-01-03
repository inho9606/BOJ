// time: O(10n)
#pragma warning(disable: 4996)
#include <cstdio>
int step[100][10];

int solution(int n) {
	int sum=0;
	step[0][0] = 0;
	for(int i=1; i<=9;i++)
		step[0][i] = 1;
	for(int i=1; i<n; i++) {
		for(int j=0; j<=9; j++) {
			if(j==0) step[i][j] = step[i-1][j+1];
			else if(j == 9) step[i][j] = step[i-1][j-1];
			else step[i][j] = (step[i-1][j-1] + step[i-1][j+1]) % 1000000000;
		}
	}
	for(int i=0; i<=9; i++)
		sum = (sum + step[n-1][i]) % 1000000000;
	return sum;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", solution(n));
	return 0;
}