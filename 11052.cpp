// time: O(n^2)
#pragma warning(disable: 4996)
#include <cstdio>
int p[10001];

int solution(int n) {
	int dp[10001];
	int m;
	for(int i=1; i<=n; i++) {
		m = p[i];
		if(i > 0) {
			for(int j=1; j<i; j++)
				if(dp[i-j]+p[j] > m) m = dp[i-j] + p[j];
		}
		dp[i] = m;
	}
	return dp[n];
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &p[i]);
	printf("%d", solution(n));
	return 0;
}