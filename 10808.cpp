// time: O(n)
#include <cstdio>

int main() {
	char s[100];
	int n[26];
	for(int i=0; i<26; i++) n[i] = 0;
	scanf("%s", s);
	for(int i=0; s[i] != '\0'; i++) {
		n[s[i]-'a'] += 1;
	}
	for(int i=0; i<26; i++)
		printf("%d ", n[i]);
	return 0;
}