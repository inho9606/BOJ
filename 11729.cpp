#include <iostream>
#include <vector>
using namespace std;
void solution(int n, int a, int b, int c) {
	if(n==0) return;
	solution(n-1,a,c,b);
//	cout << a << " " << c << endl;
	printf("%d %d\n", a, c);
	solution(n-1,b,a,c);
}

int main() {
	int n, count=1;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		count*=2;
	printf("%d\n", count-1);
	solution(n,1,2,3);
	return 0;
}