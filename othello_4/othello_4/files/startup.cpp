#include <stdio.h>
#include "startup.h"

/* �N�����̉�ʕ\�� */
void startup(char field[][LEN]) {
	printf("Welcome to Othello Game!!\n\n");
	printField(field);

	printf("Please some key press. Game will start.\n");
	getchar();
}