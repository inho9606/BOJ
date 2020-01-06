// time: O(n)
#pragma warning(disable: 4996)
#include <cstdio>
int wine[10000];

int solution(int n) {
	int answer;
	int f = new f[n];
	f[0] = wine[0];
	f[1] = wine[0] + wine[1];
	f[2] = wine[0] + wine[2];
	for(int i=2; i<n; i++) {
		if(f[i-2] + wine[i] > f[i-3] + wine[i-1] + wine[i]) f[i] = f[i-2] + wine[i];
		else f[i] = f[i-3] + wine[i-1] + wine[i];
		if(f[i-1] > f[i]) f[i] = f[i-1];
	}
	answer = f[n-1];
	delete[] f;
	return answer;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &wine[i]);
	solution(0, 0, n, 0);
	printf("%d", max);
	return 0;
}