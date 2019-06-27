#include <stdio.h>
#include "setpos.h"

/* 指定座標に指定文字が置けるかチェックする */
int setPos(int Y, int X, char c, char f[LEN][LEN], int set) {
	int count = 0;

	//上方向
	count += directCount(Y, X, -1, 0, c, f, set);
	//下方向
	count += directCount(Y, X, 1, 0, c, f, set);
	//左方向
	count += directCount(Y, X, 0, -1, c, f, set);
	//右方向
	count += directCount(Y, X, 0, 1, c, f, set);
	//左上方向
	count += directCount(Y, X, -1, -1, c, f, set);
	//右上方向
	count += directCount(Y, X, 1, -1, c, f, set);
	//左下方向
	count += directCount(Y, X, -1, 1, c, f, set);
	//右下方向
	count += directCount(Y, X, 1, 1, c, f, set);
	//ここで入力を行っている。cにはplayerが入る。
	if (set && count) f[Y][X] = c;

	return count; //置けない
}

/* 指定方向へのカウント */
int directCount(int y, int x, int dy, int dx, char c, char f[LEN][LEN], int set) {
	int i;
	int count = 0;
	char* p;

	x += dx;
	y += dy;

	//cと同じ文字を探す。「ポインタpにbeInField()を入力、アドレス*pがcでないとき繰り返しを抜ける」
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

	//フィールドの端まで達したとき
	// p は NULL
	//同じ文字が見つかったとき
	// p は cに等しい
	if (p == NULL) count = 0;

	// 裏返し処理
	if (set && count > 0) {
		x -= dx;
		y -= dy;
		for (i = 0; i < count; i++) {
			f[y][x] = c;//コマをひっくり返している。
			x -= dx;
			y -= dy;
		}
	}

	return count;
}

/* 座標がフィールド内かどうか判定する関数 */
char* beInField(char field[LEN][LEN], int y, int x) {
	// フィールド内ならポインタを返す
	if (x >= 0 && x < LEN && y >= 0 && y < LEN) return &field[y][x];

	// フィールド外ならNULL
	return NULL;
}
