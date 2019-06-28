#include <stdio.h>
#include "startup.h"

void printField(char f[LEN][LEN]) {
	int x, y;

	for (x = 0; x < LEN; x++) printf(x ? "  %d " : "     %d ", x);
	printf("\n");
	printf("   +---+---+---+---+---+---+---+---+\n");

	for (y = 0; y < LEN; y++) {
		printf(" %d |", y);
		for (x = 0; x < LEN; x++) {
			printf(x ? " %c |" : " %c |", f[y][x]);
		}
		printf("\n");
		printf("   +---+---+---+---+---+---+---+---+\n");
	}
	printf("\n");
}
