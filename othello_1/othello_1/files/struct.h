#ifndef _STRUCT_H_
#define _STRUCT_H_

// �Z���̏��i������j
typedef struct cell {
	int x;
	int y;
	char* p_cell;
	int count;
} CELL;

// �t�B�[���h���\����
typedef struct finfo {
	int white;
	int black;
	int blank;
} F_INFO;

#endif // _STRUCT_H_