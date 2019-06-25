#include <stdio.h>
#include "startup.h"
#include "chooseturn.h"


/* 先攻、後攻の選択画面表示 */
int chooseturn() {
	int x;

	do{

	printf("You could choose turn.(first:0,second:1)\n\n");
	// ユーザ入力を受け取る
	printf("please input: ");
	scanf("%d", &x);


	} while (x > 1);

	return x;
}