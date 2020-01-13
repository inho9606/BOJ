#pragma warning(disable: 4996) 
#include <cstdio>
char o[333333];

int main() {
	int n = 0, t = 0, m;
	char answer[1000000];
	scanf("%s", o);
	for (int i = 0; o[i] != '\0'; i++) n++;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = o[i] - 48; j > 0; j /= 2)
			answer[t++] = (j % 2)+48;
		if (o[i] - 48 < 4) answer[t++] = 48;
		if (o[i] - 48 < 2) answer[t++] = 48;
		if (o[i] - 48 == 0) answer[t++] = 48;
	}
	for(m=t-1; m>=0 && answer[m] == 48; m--) ;
	if(m<0) printf("%d", 0);
	else {
		for (int i = m; i >= 0; i--)
			printf("%c", answer[i]);
	}
	return 0;
}