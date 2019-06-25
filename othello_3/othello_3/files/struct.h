#ifndef _STRUCT_H_
#define _STRUCT_H_

// セルの情報（取れる個数）
typedef struct cell {
	int x;
	int y;
	char* p_cell;
	int count;
} CELL;

// フィールド情報構造体
typedef struct finfo {
	int white;
	int black;
	int blank;
} F_INFO;

#endif // _STRUCT_H_