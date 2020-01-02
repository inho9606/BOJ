#pragma warning(disable: 4996) 
#include <cstdio>
int main() {
	char s[100];
	scanf("%[^\n]", s);
	for(int i=0; s[i] != '\0'; i++) {
		if((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M')) s[i] += 13;
		else if((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z')) s[i] -= 13;
	}
	for(int i=0; s[i] != '\0'; i++)
		printf("%c", s[i]);
	return 0;
}