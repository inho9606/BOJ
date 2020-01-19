// the number of zero on n! is the number of the smaller one between the number of two and five on prime factors of n!
// n 펙토리얼에서 0의 개수는 n 펙토리얼을 소인수분해 한 다음 10의 개수이므로, 2와 5를 지수로 같은 수 중 작은 것을 고르면 된다.
// time: O(n*n/2)?
#include <cstdio>

int main() {
	int n, j, two=0, five=0;
	scanf("%d", &n);
	for(int i=2; i<=n; i++) {
		for(j=i; j>0 && j%2==0; j/=2) two++;
		for(; j>1 && j%5==0; j/=5) five++;
	}
	if(two < five) printf("%d", two);
	else printf("%d", five);
	return 0;
}