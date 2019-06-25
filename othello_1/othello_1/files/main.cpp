#include <stdio.h>
#include "startup.h"
#include "screen.h"
#include "player.h"
#include "viewstatus.h"
#include "chooseturn.h"



int main(int argc, char** argv) {
	char field[LEN][LEN];	// 8x8の文字型2次元配列
	char player;		// 人間のコマ
	int available;		// パス，終了判定フラグ
	F_INFO info;		// 盤面情報（コマ，空白の個数）
//	int blcnt = 0;		// 空白セル数のカウント
	int x;				//先攻か後攻を選択する変数

	// 盤面の初期化
	initField(field);

	// スタート画面の表示
	startup(field);

/*追加はここから*/
	//先攻か後攻を選択する変数xに値を入力
	x = chooseturn();
/*追加はここまで*/


/*追加はここから*/
	if (x == 0) {

		player = WHITE;
		printf("Your turn is first.\n");
		wait(2);

	}
	else if (x == 1) {

		player = BLACK;
		printf("Your turn is second.\n");
		wait(2);

	};
/*追加はここまで*/

	cls();


	// ゲーム開始
	printf("GAME START!!\n");
	wait(2);

	// ゲームループ
	do {
			cls();
			available = 0;

/*追加はここから*/
			if (player == WHITE ) {
/*追加はここまで*/

				/* 人間の手番 */
				printf("Your('%c') turn:\n", player);
				printField(field);

				available |= human(field, player);

				cls();
				//avaialable=0ならelseへ
				if (available) {
					printf("Your('%c') turn:\n", player);
					printField(field);
				}
				else printf("\tYou: Pass!\n");

/*追加はここから*/
				player = BLACK;
/*追加はここまで*/

				wait(1);
			
/*追加はここから*/
			};

			if (player == BLACK) {
/*追加はここまで*/

				/* コンピュータの手番 */
//				available |= cpu(field, player == WHITE ? BLACK : WHITE);
/*↑変更前↑＿↓変更後↓*/
				available |= cpu(field, player);

				cls();
				if (available) {
					printf("CPU's turn:\n\n");
					printField(field);
				}
				else printf("\tCPU: Pass!\n");

				viewStatus(field);

				printf("\n");

/*追加はここから*/
				player = WHITE;
/*追加はここまで*/
				wait(1);

/*追加はここから*/
			};
/*追加はここまで*/

		} while (available);

		// ゲーム終了処理
		cls();

		printf("GAME FINISHED!!\n");

		printField(field);

		viewStatus(field);

		info = fieldStatus(field);
		printf("\tResult: ");
		if (info.black == info.white) {
			printf("EVEN\n");
		}
		else if (info.black > info.white) {
			printf("BLACK WIN!!  WHITE FAILED\n");
		}
		else {
			printf("WHITE WIN!!  BLACK FAILED\n");
		}

		return 0;
}