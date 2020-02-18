#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
using namespace std;

int main() {
		int n, m, i, j, k=0;
		scanf("%d%d", &n, &m);
		vector<int> a(n), b(m), c(n+m);
		for(i=0; i<n; i++)
			scanf("%d", &a[i]);
		for(i=0; i<m; i++)
			scanf("%d", &b[i]);
		i=0; j=0;
		while(i<n && j<m) {
			if(a[i] < b[j]) {
				c[k++] = a[i];
				i++;
			}
			else {
				c[k++] = b[j];
				j++;
			}
		}
		if(i<n) {
			for(; i<n; i++)
				c[k++] = a[i];
		}
		else if(j<m) {
			for(; j<m; j++)
				c[k++] = b[j];
		}
	for(i=0; i<n+m; i++)
		printf("%d ", c[i]);
	return 0;
}