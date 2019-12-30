#include <cstdio>

int main() {
	char word[100];
	int length=0;
	scanf("%s", word);
	for(int i=0; word[i] != '\0'; i++)
		length++;
	printf("%d", length);
	return 0;
}