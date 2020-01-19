// the number of zero on n! is the number of the smaller one between the number of two and five on prime factors of n!
// n ���丮�󿡼� 0�� ������ n ���丮���� ���μ����� �� ���� 10�� �����̹Ƿ�, 2�� 5�� ������ ���� �� �� ���� ���� ���� �ȴ�.
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