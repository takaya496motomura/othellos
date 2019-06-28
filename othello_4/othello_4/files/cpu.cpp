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
	int i,x; //xはCPUのレベル


	bc = blankCellCount(f); // 空白セル数

	bl = (CELL*)malloc(sizeof(CELL) * bc); //1つ分あらかじめ確保
	if (bl == NULL) {
		printf("malloc Error!\n");
		return -1;
	}

	availableCellList(f, bl, player); // 取得

	x = 2;//CPUは弱

	if (x == 1) {
		for (i = 0; i < bc; i++) {
			if (bl[i].count > better) {
				better = bl[i].count; // とりあえず最後の最善手(周囲8マスに置ける最大数)
				better_cell = bl[i];
			}
		}
	}
	else if (x == 2) {
		for (i = 0; i < bc; i++) {
			if ( bl[i].count > 0 ) { // available=0を除外する必要がある（空白のマスでも代入されてしまうため）
				better = bl[i].count; // とりあえず最後に置けるマス
				better_cell = bl[i];
			}
		}
	}

	if (better > 0) {
		// 実際に置く
		setPos(better_cell.y, better_cell.x, player, f, 1);
	}

	free(bl);

	return better;
}