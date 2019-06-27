#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "setpos.h"


/* コンピュータの手番 */
int cpu(char f[LEN][LEN], char player) {
	CELL* bl;
	int bc;
	int better = 0;
	CELL better_cell;
	int i;

	bc = blankCellCount(f); // 空白セル数

	bl = (CELL*)malloc(sizeof(CELL) * bc); //1つ分あらかじめ確保
	if (bl == NULL) {
		printf("malloc Error!\n");
		return -1;
	}

	availableCellList(f, bl, player); // 取得

	/* ここから */

	for (i = 0; i < bc; i++) {
		if (bl[i].count > better) {
			better = bl[i].count; // とりあえず最後の最善手で
			better_cell = bl[i];
		}
	}


	if (better > 0) {
		// 実際に置く
		setPos(better_cell.y, better_cell.x, player, f, 1);
	}

	/* ここまで */
	free(bl);

	return better;
}