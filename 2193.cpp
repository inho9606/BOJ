#pragma warning(disable: 4996)
#include <cstdio>
long long solution(int n) {
	long long f[90];
	f[0] = 1;
	f[1] = 1;
	for(int i=2; i<n; i++)
		f[i] = f[i-1] + f[i-2];
	return f[n-1];
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", solution(n));
	return 0;
}