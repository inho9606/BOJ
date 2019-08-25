				#define _CRT_SECURE_NO_WARNINGS
				#pragma warning(disable:4996)
				#include <stdio.h>
				#include <stdlib.h>

				int hansoo(int n) {
					if (n / 100 != 0 && (n % 100 / 10) - (n / 100) == (n % 100 % 10) - (n % 100 / 10))
						return 1;
					else if (n/10 <10)
						return 1;
					else return 0;
				}

				int main() {
					int n, count=0;
					scanf("%d", &n);
					for (int i = 1; i <= n; i++)
						count += hansoo(i);
					printf("%d\n", count);
					return 0;
				}

