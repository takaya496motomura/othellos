#include <stdio.h>
#include "startup.h"
#include "chooseturn.h"


/* ��U�A��U�̑I����ʕ\�� */
int chooseturn() {
	int x;

	do{

	printf("You could choose turn.(first:0,second:1)\n\n");
	// ���[�U���͂��󂯎��
	printf("please input: ");
	scanf("%d", &x);


	} while (x > 1);

	return x;
}