// time: O(n^2/4)
#pragma warning(disable: 4996)
#include <cstdio>

int solution(int n) {
	int answer=0;
	if(n % 2 != 0) return answer;
	int* f = new int[n+1];
	f[0] = 1;
	for(int i=2; i<=n; i+=2) {
		f[i] = f[i-2]*3;
		for(int j=4; j<=i; j+=2)
			f[i] += f[i-j]*2;
	}
	answer = f[n];
	delete[] f;
	return answer;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", solution(n));
	return 0;
}