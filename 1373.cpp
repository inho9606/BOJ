#pragma warning(disable: 4996) 
#include <cstdio>

int main() {
	int m=1, n=0, t=0, l=0;
	char answer[1000000], b[1000000];
	scanf("%s", b);
	for(int i=0; b[i] != '\0'; i++) n++;
	for(int i=n-1; i>=0; i--) {
		t += (b[i]-48)*m;
		if(m>=4 || i == 0) {
			answer[l++] = t+48;
			m=1;
			t = 0;
		}
		else m*=2;
	}
	for(int i=l-1; i>=0; i--)
		printf("%c", answer[i]);
	return 0;
}