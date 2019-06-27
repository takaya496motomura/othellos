#include "viewstatus.h"

void initField(char f[LEN][LEN]) {
	int x, y;

	for (y = 0; y < LEN; y++) {
		for (x = 0; x < LEN; x++) {
			f[y][x] = ' ';
		}
	}

	// ‰ŠúˆÊ’u
	f[3][3] = f[4][4] = WHITE;
	f[4][3] = f[3][4] = BLACK;
}
