#include <stdio.h>
#include "setpos.h"


/* 空白セルのカウント */
int blankCellCount(char f[LEN][LEN]) {
	int x, y;
	int blcnt = 0;

	for (y = 0; y < LEN; y++) {
		for (x = 0; x < LEN; x++) {
			if (f[y][x] == ' ') {
				blcnt++;
			}
		}
	}

	return blcnt;
}


void availableCellList(char f[LEN][LEN], CELL* list, char player) {
	int x, y;
	int blcnt = 0;

	for (y = 0; y < LEN; y++) {
		for (x = 0; x < LEN; x++) {
			if (f[y][x] == ' ') {
				blcnt++;
				// セルの情報を格納
				list[blcnt - 1].x = x;
				list[blcnt - 1].y = y;
				list[blcnt - 1].p_cell = &f[y][x];
				list[blcnt - 1].count = setPos(y, x, player, f, 0);
			}
		}
	}

}