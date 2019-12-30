#include <cstdio>

int main() {
	char s[100];
	int n=0, sum=0;
	scanf("%s", s);
	for(int i=0; s[i] != '\0'; i++) {
		if(s[i] == ',') { sum += n; n=0; }
		else {
			n*=10;
			n += s[i] - 48;
		}
	}
	sum += n;
	printf("%d", sum);
	return 0;
}