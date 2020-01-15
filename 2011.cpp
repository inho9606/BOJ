// time: O(n)
#pragma warning(disable: 4996) 
#include <cstdio>

int solution(char* p, int n) {
	int answer;
	int* c = new int[n+1];
	c[0] = 1;
	for(int i=0; i<n; i++) {
		if(i==0) {
			if(p[i] == 48) return 0;
			c[1] = 1;
			continue;
		}
		if((p[i] >= 55 && p[i-1] >= 50) || (p[i-1] == 48 && p[i] >48 && p[i] < 58) || (p[i] > 48 && p[i-1] > 50)) c[i+1] = c[i];
		else if(p[i] == 48 && (p[i-1] == 49 || p[i-1] == 50)) c[i+1] = c[i-1];
		else c[i+1] = (c[i] + c[i-1]) % 1000000;
	}
	answer = c[n];
	delete[] c;
	return answer;
}

int main() {
	char p[5000];
	int n=0;
	scanf("%s", p);
	for(int i=0; p[i] != '\0'; i++) n++;
	printf("%d", solution(p, n));
	return 0;
}