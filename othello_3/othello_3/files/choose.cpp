#include <stdio.h>
#include "startup.h"
#include "choose.h"
#include "screen.h"



/* 先攻、後攻の選択画面表示 */
int choosepiece() {
	int x;

	do{

	printf("Player1 would choose turn.(first:0,second:1)\n\n");
	// ユーザ入力を受け取る
	printf("please input: ");
	scanf("%d", &x);

	} while (x > 1);

	if (x == 0) {

		//	player = WHITE;
		printf("Your turn is first.\n\n");
		printf("Player1 is BLACK('X') piece.\n\n");
		printf("Player2 is WHITE('O') piece.\n\n");
		wait(4);

	}
	else if (x == 1) {

		//	player = BLACK;
		printf("Your turn is second.\n\n");
		printf("Player1 is WHITE('O') piece.\n\n");
		printf("Player2 is BLACK('X') piece.\n\n");
		wait(4);

	};

	cls();

	return x;
}

/* ローカル対戦かCPU対戦の選択画面を表示 */
int choosemode() {
	int x;

	do {

		printf("Player1 would choose battle mode.(CPU battle:0,Interpersonal battle:1)\n\n");
		// ユーザ入力を受け取る
		printf("please input: ");
		scanf("%d", &x);


	} while (x > 1);

	if (x == 0) {

		printf("Playing CPU battle mode.\n\n");
		wait(4);

	}
	else if (x == 1) {

		printf("Playing Interpersonal battle mode.\n\n");
		wait(4);

	};

	cls();

	return x;
}

/* 先攻、後攻の選択画面表示CPU版 */
int chooseturn() {
	int x;

	do {

		printf("Player would choose turn.(first:0,second:1)\n\n");
		// ユーザ入力を受け取る
		printf("please input: ");
		scanf("%d", &x);

	} while (x > 1);

	if (x == 0) {

		//	player = WHITE;
		printf("Your turn is first.\n\n");
		wait(4);

	}
	else if (x == 1) {

		//	player = BLACK;
		printf("Your turn is second.\n\n");
		wait(4);

	};

	cls();

	return x;
}