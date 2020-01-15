#pragma warning(disable: 4996) 
#include <cstdio>

typedef struct tree* ptr;
typedef struct tree {
	char value;
	ptr left;
	ptr right;
}tree;

int main() {
	int n;
	ptr root = new tree;
	root.value = 'A';
	printf("%c", root.value);
	delete[] root;
	return 0;
}