#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int* ns = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d", &ns[i]);
	sort(ns, ns+n);
	printf("%d %d", ns[0], ns[n-1]);
	delete[] ns;
	return 0;
}