// time: O(n*10*10)
// 정확하게는 (시그마 1:10)*n 아닌가..
#	pragma warning(disable: 4996)
#include <cstdio>
int increased[1000][10];

int solution(int n) {
	int sum=0;
	for (int i = 0; i < 10; i++)
		increased[0][i] = 1;
	for(int i=1; i<n; i++) {
		for(int j=0; j<10; j++) {
			for(int k=j; k<10; k++)
				increased[i][j] = (increased[i][j] + increased[i-1][k]) % 10007;
		}
	}
	for(int i=0; i<10; i++)
		sum = (sum+increased[n-1][i]) % 10007;
	return sum;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", solution(n));
	return 0;
}