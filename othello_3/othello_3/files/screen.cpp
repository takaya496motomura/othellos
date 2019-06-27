#include <stdio.h>
#include "screen.h"


/* 画面クリア関数 */
void cls() {
	// Windows環境への対応（Visual C++）
#ifdef _MSC_VER
	system("cls");
#else
	printf("\n\x1b[2J\n");
#endif
}


/* 一定時間待機させる関数 */
void wait(int sec) {
	// Visual C++コンパイラへの対応
#ifdef _MSC_VER
	Sleep(sec * 1000);

#else
	//sleep(sec);
#endif
}

/* 入力待ち */
void pause() {
	// Windows環境への対応（Visual C++）
#ifdef _MSC_VER
	system("pause");
#else
	printf("\n\x1b[2J\n");
#endif
}
