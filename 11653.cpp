// n으로 나눌 수 없는 값은 n의 배수로 나눌 수 없다.
#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for(int i=2; i*i<=n; i++) {
		for(; n%i==0; n/=i)
			printf("%d\n", i);
	}
	if(n>1) printf("%d\n", n);
	return 0;
}