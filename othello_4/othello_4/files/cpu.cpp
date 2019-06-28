#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "setpos.h"


/* �R���s���[�^�̎�� */
int cpu(char f[LEN][LEN], char player) {
	CELL* bl;
	int bc;
	int better = 0;
	CELL better_cell;
	int i,x; //x��CPU�̃��x��


	bc = blankCellCount(f); // �󔒃Z����

	bl = (CELL*)malloc(sizeof(CELL) * bc); //1�����炩���ߊm��
	if (bl == NULL) {
		printf("malloc Error!\n");
		return -1;
	}

	availableCellList(f, bl, player); // �擾

	x = 2;//CPU�͎�

	if (x == 1) {
		for (i = 0; i < bc; i++) {
			if (bl[i].count > better) {
				better = bl[i].count; // �Ƃ肠�����Ō�̍őP��(����8�}�X�ɒu����ő吔)
				better_cell = bl[i];
			}
		}
	}
	else if (x == 2) {
		for (i = 0; i < bc; i++) {
			if ( bl[i].count > 0 ) { // available=0�����O����K�v������i�󔒂̃}�X�ł��������Ă��܂����߁j
				better = bl[i].count; // �Ƃ肠�����Ō�ɒu����}�X
				better_cell = bl[i];
			}
		}
	}

	if (better > 0) {
		// ���ۂɒu��
		setPos(better_cell.y, better_cell.x, player, f, 1);
	}

	free(bl);

	return better;
}