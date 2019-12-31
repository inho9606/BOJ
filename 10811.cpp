// time: O(m(k-j)+n)
#pragma warning(disable: 4996) 
#include <cstdio>
int basket[100];

void reverse(int j, int k) {
	int* tmp = new int[k-j+1];
	for(int i=0; i<k-j+1; i++)
		tmp[i] = basket[k-i-1];
	for(int i=0; i<k-j+1; i++)
		basket[j+i-1] = tmp[i];
	delete[] tmp;
}
int main() {
	int n, m, k, l;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
		basket[i] = i+1;
	for(int i=0; i<m; i++) {
		scanf("%d%d", &k, &l);
		reverse(k, l);
	}
	for(int i=0; i<n; i++)
		printf("%d ", basket[i]);
	return 0;
}
