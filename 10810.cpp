// time: O(m(k-j)+n)
#include <cstdio>
int ball[100];

int main() {
	int n, m, j, k, l;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%d%d%d", &j, &k, &l);
		for(int ii=j; ii<=k; ii++)
			ball[ii-1] = l;
	}
	for(int i=0; i<n; i++)
		printf("%d ", ball[i]);
	return 0;
}