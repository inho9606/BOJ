				#define _CRT_SECURE_NO_WARNINGS
				#include <stdio.h>
				#include <stdlib.h>

int main() {
	int stations[4], on, off, persons=0;
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &off, &on);
		if (i == 0)
			stations[i] = on;			
		else {
			stations[i] = stations[i - 1] - off;
			stations[i] += on;
		}
			if (stations[i] >= persons) persons = stations[i];
	}
	printf("%d\n", persons);
	return 0;
}