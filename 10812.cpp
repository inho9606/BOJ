// time: O(m(k-j)+n)
#pragma warning(disable: 4996) 
#include <cstdio>
int basket[100];

void reverse(int j, int k, int m) {
	int i;
	int* tmp = new int[k-j+1];
	for(i=0; i<k-m+1; i++)
		tmp[i] = basket[m+i-1];
	for(int ii=0; ii<k-j+1-i; ii++)
		tmp[ii+i] = basket[j+ii-1];
	for(int i=0; i<k-j+1; i++)
		basket[j+i-1] = tmp[i];
	delete[] tmp;
}
int main() {
	int n, m, k, l, j;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
		basket[i] = i+1;
	for(int i=0; i<m; i++) {
		scanf("%d%d%d", &j, &k, &l);
		reverse(j, k, l);
	}
	for(int i=0; i<n; i++)
		printf("%d ", basket[i]);
	return 0;
}