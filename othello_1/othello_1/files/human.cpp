#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "setpos.h"


/* コンピュータの手番 */
int human(char f[LEN][LEN], char player) {
	CELL* bl;
	int bc;
	int better = 0;
	CELL better_cell;
	int i;
	int x, y;
	int check;

	bc = blankCellCount(f); // 空白セル数

	bl = (CELL*)malloc(sizeof(CELL) * bc); //1つ分あらかじめ確保
	if (bl == NULL) {
		printf("malloc Error!\n");
		return -1;
	}

	availableCellList(f, bl, player); // 取得

	/* ここから */

	for (i = 0; i < bc; i++) {
		if (bl[i].count > better) { //betterの初期値0なので、空白最後の要素のcountをbetterに入れている
			better = bl[i].count; // とりあえず最後の最善手で
			better_cell = bl[i];//構造体の変数better_cellの構造体に配列bl[i]を入力
		}
	}
	/*自分のコマがおけない処理（デバック用）*/
///	better = 0;

	if (better > 0) {
		do {
			// ユーザ入力を受け取る
			printf("please input: ");
			scanf("%d %d", &x, &y);

			// 実際に置く
			check = setPos(y, x, player, f, 1);
		} while (check == 0);
	}

	/* ここまで */

	free(bl);

	return better;
}
