#pragma warning(disable: 4996) 
#include <cstdio>
#include <math.h>
int n, max=0, a[8];

void swap(int *a, int *b ){
int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}
void solution(int m, int r) {
	if(r == 0) {
		int sum=0;
		for(int i=0; i<n-1; i++) sum += abs(a[i] - a[i+1]);
		if(sum > max) max= sum;
		return;
	}
	for(int i=m-1; i>=0; i--) {
		swap(&a[i], &a[m-1]);
		solution(m-1, r-1);
		swap(&a[i], &a[m-1]);
	}
}
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	solution(n, n);
	printf("%d", max);
	return 0;
}