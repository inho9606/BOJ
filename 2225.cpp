#pragma warning(disable: 4996) 
#include <cstdio>

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int** f = new int*[n];
	for(int i=0; i<n; i++)
		f[i] = new int[k];
	for(int i=0; i<n; i++)
		f[i][0] = 1;
	for(int i=0; i<k; i++)
		f[0][i] = i+1;
	for(int i=1; i<n; i++) {
		for(int j=1; j<k; j++) {
			f[i][j] = (f[i-1][j]+f[i][j-1]) % 1000000000;
		}
	}
	printf("%d", f[n-1][k-1]);
	delete[] f;
	return 0;
}