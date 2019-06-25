#include <stdio.h>
#include "viewstatus.h"


/* ���ꂼ��̃R�}�̐��̕\�� */
void viewStatus(char f[LEN][LEN]) {
	F_INFO info;

	// �R�}�̐����擾
	info = fieldStatus(f);
	printf("\tCount: Black('X'): %d\t", info.black);
	printf("White('O'): %d\n\n", info.white);
}

/* �t�B�[���h�ɒu����Ă���I�u�W�F�N�g�̐��𒲂ׂ� */
F_INFO fieldStatus(char f[LEN][LEN]) {
	F_INFO info = { 0, 0, 0 };
	int x, y;

	for (y = 0; y < LEN; y++) {
		for (x = 0; x < LEN; x++) {
			switch (f[y][x]) {
			case WHITE:
				info.white++;
				break;
			case BLACK:
				info.black++;
				break;
			case BLANK:
				info.blank++;
				break;
			}
		}
	}

	return info;
}