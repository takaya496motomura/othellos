#include <stdio.h>
#include "startup.h"

/* 起動時の画面表示 */
void startup(char field[][LEN]) {
	printf("Welcome to Othello Game!!\n\n");
	printField(field);

	printf("You are WHITE('O') piece.\n\n");

	printf("Please some key press. Game will start.\n");
	getchar();
}