#ifndef _SETPOS_H_
#define _SETPOS_H_

#include "define.h"
#include "struct.h"

int setPos(int y, int x, char c, char f[LEN][LEN], int set);
int directCount(int y, int x, int dy, int dx, char c, char f[LEN][LEN], int set);
char* beInField(char field[LEN][LEN], int y, int x);

void availableCellList(char f[LEN][LEN], CELL* list, char player);
int blankCellCount(char f[LEN][LEN]);


#endif // _SETPOS_H_