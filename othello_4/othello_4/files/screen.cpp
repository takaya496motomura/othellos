#include <stdio.h>
#include "screen.h"


/* ��ʃN���A�֐� */
void cls() {
	// Windows���ւ̑Ή��iVisual C++�j
#ifdef _MSC_VER
	system("cls");
#else
	printf("\n\x1b[2J\n");
#endif
}


/* ��莞�ԑҋ@������֐� */
void wait(int sec) {
	// Visual C++�R���p�C���ւ̑Ή�
#ifdef _MSC_VER
	Sleep(sec * 1000);

#else
	//sleep(sec);
#endif
}

/* ���͑҂� */
void pause() {
	// Windows���ւ̑Ή��iVisual C++�j
#ifdef _MSC_VER
	system("pause");
#else
	printf("\n\x1b[2J\n");
#endif
}
