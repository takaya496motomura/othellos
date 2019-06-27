#include <stdio.h>
#include "startup.h"
#include "screen.h"
#include "player.h"
#include "viewstatus.h"
#include "choose.h"



int main(int argc, char** argv) {
	char field[LEN][LEN];	// 8x8の文字型2次元配列
	char player;		// 人間のコマ
	int available;		// パス，終了判定フラグ
	F_INFO info;		// 盤面情報（コマ，空白の個数）
//	int blcnt = 0;		// 空白セル数のカウント
	int x,y;				//先攻か後攻を選択する引数

	// 盤面の初期化
	initField(field);

	// スタート画面の表示
	startup(field);

	// CPU対戦かローカル対戦を選択
	y = choosemode();

	// 対戦方法ごとで先攻後攻を選択
	if (y == 1) {
		x = choosepiece();
	}
	else {
		x = chooseturn();
	}

	cls();

	/*先攻はBLACKが国際ルール*/
	player = BLACK;

	// ゲーム開始
	printf("GAME START!!\n");
	wait(2);

	// ゲームループ
	do {
			cls();
			available = 0;

			if (y == 1) {

				//ローカル対戦
				if (player == BLACK) {

					cls();
					/* 人間1の手番 */
					printf("Your('%c') turn:\n", player);
					printField(field);

					available |= human(field, player);

					cls();
					if (available) {
						printf("Your('%c') turn:\n", player);
						printField(field);
					}
					else printf("\tYou: Pass!\n");

					viewStatus(field);

					printf("\n");

					player = WHITE;
					wait(2);

				};

				if (player == WHITE) {

					cls();
					/* 人間2の手番 */
					printf("Your('%c') turn:\n", player);
					printField(field);

					available |= human(field, player);

					cls();
					if (available) {
						printf("Your('%c') turn:\n", player);
						printField(field);
					}
					else printf("\tYou: Pass!\n");

					viewStatus(field);

					printf("\n");

					player = BLACK;

					wait(2);

				};

			}
			else {
				if (x == 1) {
					//CPU対戦（CPUが先攻）
					if (player == BLACK) {
	
						cls();
						/* CPUの手番 */
						printf("Your('%c') turn:\n", player);
						printField(field);
	
						available |= cpu(field, player);
	
						cls();
						//avaialable=0ならelseへ
						if (available) {
							printf("Your('%c') turn:\n", player);
							printField(field);
						}
						else printf("\tYou: Pass!\n");

						viewStatus(field);

						printf("\n");

						player = WHITE;

						wait(2);
					};
					if (player == WHITE) {
	
						cls();
						/* 人間の手番（後攻） */
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

						viewStatus(field);

						printf("\n");

						player = BLACK;

						wait(2);

					};
				}
				else {
					//CPU対戦（CPUが後攻）
					if (player == BLACK) {

						cls();
						/* 人間の手番（先攻） */
						printf("Your('%c') turn:\n", player);
						printField(field);
	
						available |= human(field, player);

						cls();
						if (available) {
							printf("Your('%c') turn:\n", player);
							printField(field);
						}
						else printf("\tYou: Pass!\n");

						viewStatus(field);

						printf("\n");

						player = WHITE;
						wait(2);

					};

					if (player == WHITE) {

						cls();
						/* CPUの手番 */
						printf("Your('%c') turn:\n", player);
						printField(field);

						available |= cpu(field, player);

						cls();
						//avaialable=0ならelseへ
						if (available) {
							printf("Your('%c') turn:\n", player);
							printField(field);
						}
						else printf("\tYou: Pass!\n");

						viewStatus(field);

						printf("\n");

						player = BLACK;

						wait(2);
					};
				};
			};
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

		// 「続行するには何かキーを押してください . . .」を表示する
		pause();

		return 0;
}