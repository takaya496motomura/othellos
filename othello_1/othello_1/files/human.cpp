#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "setpos.h"


/* �R���s���[�^�̎�� */
int human(char f[LEN][LEN], char player) {
	CELL* bl;
	int bc;
	int better = 0;
	CELL better_cell;
	int i;
	int x, y;
	int check;

	bc = blankCellCount(f); // �󔒃Z����

	bl = (CELL*)malloc(sizeof(CELL) * bc); //1�����炩���ߊm��
	if (bl == NULL) {
		printf("malloc Error!\n");
		return -1;
	}

	availableCellList(f, bl, player); // �擾

	/* �������� */

	for (i = 0; i < bc; i++) {
		if (bl[i].count > better) { //better�̏����l0�Ȃ̂ŁA�󔒍Ō�̗v�f��count��better�ɓ���Ă���
			better = bl[i].count; // �Ƃ肠�����Ō�̍őP���
			better_cell = bl[i];//�\���̂̕ϐ�better_cell�̍\���̂ɔz��bl[i]�����
		}
	}
	/*�����̃R�}�������Ȃ������i�f�o�b�N�p�j*/
///	better = 0;

	if (better > 0) {
		do {
			// ���[�U���͂��󂯎��
			printf("please input: ");
			scanf("%d %d", &x, &y);

			// ���ۂɒu��
			check = setPos(y, x, player, f, 1);
		} while (check == 0);
	}

	/* �����܂� */

	free(bl);

	return better;
}
