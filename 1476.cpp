#include <iostream>
int main() {
	int e, s, m,count;
	int i=1,j=1,k=1;
	scanf("%d %d %d", &e, &s, &m);
	for(count=1; i!=e || j!=s || k!=m; count++) {
	if(++i > 15) i=1;
	if(++j > 28) j=1;
	if(++k > 19) k=1;
	}
	printf("%d", count);
	return 0;
}