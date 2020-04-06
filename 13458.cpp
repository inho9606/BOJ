// https://www.acmicpc.net/problem/13458
#include <iostream>
#include <vector>
using namespace std;

int solution(int a, int b, int c) {
	int p=1;
	a -= b;
	if(a>0) {
		p += a/c;
		if(a%c != 0) p+=1;
	}
	return p;
}
int main() {
	int n, b, c;
	long long ans=0;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	scanf("%d%d", &b,&c);
	for(int i=0; i<n; i++)
		ans += solution(a[i], b, c);
	printf("%lld", ans);
	return 0;
}