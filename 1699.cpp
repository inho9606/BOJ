#include <cstdio>
int s[100000];

int solution(int n) {
	s[0] = 0;
	for(int i=1; i<=n; i++)
		s[i] = i;
	for(int i=1; i<=n; i++) {
		for(int j=1; j*j<=i; j++) {
			if(s[i-j*j]+1 < s[i]) s[i] = s[i-j*j]+1;
		}
	}
	return s[n];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", solution(n));
	return 0;
}