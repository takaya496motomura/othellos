#include <stdio.h>
#include "setpos.h"

/* �w����W�Ɏw�蕶�����u���邩�`�F�b�N���� */
int setPos(int Y, int X, char c, char f[LEN][LEN], int set) {
	int count = 0;

	//�����
	count += directCount(Y, X, -1, 0, c, f, set);
	//������
	count += directCount(Y, X, 1, 0, c, f, set);
	//������
	count += directCount(Y, X, 0, -1, c, f, set);
	//�E����
	count += directCount(Y, X, 0, 1, c, f, set);
	//�������
	count += directCount(Y, X, -1, -1, c, f, set);
	//�E�����
	count += directCount(Y, X, 1, -1, c, f, set);
	//��������
	count += directCount(Y, X, -1, 1, c, f, set);
	//�E������
	count += directCount(Y, X, 1, 1, c, f, set);
	//�����œ��͂��s���Ă���Bc�ɂ�player������B
	if (set && count) f[Y][X] = c;

	return count; //�u���Ȃ�
}

/* �w������ւ̃J�E���g */
int directCount(int y, int x, int dy, int dx, char c, char f[LEN][LEN], int set) {
	int i;
	int count = 0;
	char* p;

	x += dx;
	y += dy;

	//c�Ɠ���������T���B�u�|�C���^p��beInField()����́A�A�h���X*p��c�łȂ��Ƃ��J��Ԃ��𔲂���v
	while ((p = beInField(f, y, x)) && (*p != c)) {
		if (*p == ' ') {
			count = 0;
			break;
		}
		else {
			count++;
		}
		x += dx;
		y += dy;
	}

	//�t�B�[���h�̒[�܂ŒB�����Ƃ�
	// p �� NULL
	//�������������������Ƃ�
	// p �� c�ɓ�����
	if (p == NULL) count = 0;

	// ���Ԃ�����
	if (set && count > 0) {
		x -= dx;
		y -= dy;
		for (i = 0; i < count; i++) {
			f[y][x] = c;//�R�}���Ђ�����Ԃ��Ă���B
			x -= dx;
			y -= dy;
		}
	}

	return count;
}

/* ���W���t�B�[���h�����ǂ������肷��֐� */
char* beInField(char field[LEN][LEN], int y, int x) {
	// �t�B�[���h���Ȃ�|�C���^��Ԃ�
	if (x >= 0 && x < LEN && y >= 0 && y < LEN) return &field[y][x];

	// �t�B�[���h�O�Ȃ�NULL
	return NULL;
}
