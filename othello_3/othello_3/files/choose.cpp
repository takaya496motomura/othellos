#include <stdio.h>
#include "startup.h"
#include "choose.h"
#include "screen.h"



/* ���[�J���ΐ�ł̐�U�A��U�̑I����ʕ\�� */
int choosepiece() {
	int x;

	do{

	printf("Player1 would choose turn.(first:0,second:1)\n\n");
	// ���[�U���͂��󂯎��
	printf("please input: ");
	scanf("%d", &x);

	} while (x > 1);

	if (x == 0) {

		printf("Your turn is first.\n\n");
		printf("Player1 is BLACK('X') piece.\n\n");
		printf("Player2 is WHITE('O') piece.\n\n");
		wait(4);

	}
	else{

		printf("Your turn is second.\n\n");
		printf("Player1 is WHITE('O') piece.\n\n");
		printf("Player2 is BLACK('X') piece.\n\n");
		wait(4);

	};

	cls();

	return x;
}

/* ���[�J���ΐ킩CPU�ΐ�̑I����ʂ�\�� */
int choosemode() {
	int x;

//	do {

//		printf("Player1 would choose battle mode.(CPU battle:0,Interpersonal battle:1)\n\n");
		// ���[�U���͂��󂯎��
//		printf("please input: ");
//		scanf("%d", &x);

//	} while (x > 1);

	while (1) {
		printf("Player1 would choose battle mode.(CPU battle:0,Interpersonal battle:1)\n\n");
		if (scanf("%d", &x) == 1 && x >= 0 && x <= 1) break; //�C����
		if (feof(stdin)) return 1;
		printf("���l������������܂���B������x���͂��Ă��������B\n");
		scanf("%*[^\n]");
	}

	if (x == 0) {

		printf("Playing CPU battle mode.\n\n");
		wait(4);

	}
	else{

		printf("Playing Interpersonal battle mode.\n\n");
		wait(4);

	};

	cls();

	return x;
}

/* CPU�ΐ�ł̐�U�A��U�̑I����ʕ\�� */
int chooseturn() {
	int x;

	do {

		printf("Player would choose turn.(first:0,second:1)\n\n");
		// ���[�U���͂��󂯎��
		printf("please input: ");
		scanf("%d", &x);

	} while (x > 1);

	if (x == 0) {

		printf("Your turn is first.\n\n");
		wait(4);

	}
	else{

		printf("Your turn is second.\n\n");
		wait(4);

	};

	cls();

	return x;
}