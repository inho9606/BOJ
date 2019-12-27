#include <cstdio>
using namespace std;

int solution(int n) {
	int answer;
	int f[20];
	f[0] = 0;
	f[1] = 1;
	for(int i=2; i<=n; i++)
		f[i] = f[i-2] + f[i-1];
	answer = f[n];
	return answer;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", solution(n));
	
	return 0;
}