// time: O(tn)
#include <cstdio>

int main() {
	int t, n, dp[1000];
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		scanf("%d", &n);
		for(int j=3; j<n; j++)
			dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
		printf("%d\n", dp[n-1]);
	}
	return 0;
}