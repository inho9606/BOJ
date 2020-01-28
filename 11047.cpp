// time: almost O(n)?
#include <cstdio>

int solution(int* f, int n, int k) {
	int t=k, answer = 0;
	for(int i=n-1; i>=0; i--) {
		if(f[i] <= t) {
			t -= f[i];
			answer++;
			i++;
		}
		if(t == 0) break;
	}
	return answer;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int* f = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d", &f[i]);
	printf("%d", solution(f, n, k));
	delete[] f;
	return 0;
}