#include "../include/utils.h"



void clampy(int* y,int maxy){
	if(*y < 1)	*y = 1;
	if(*y > maxy) *y = maxy;
}

void clampx(int* x,int maxx){
	if(*x < 1) *x = 1;
	if(*x > maxx) *x = maxx;
}



void initCurses(){
	initscr();
	curs_set(0);
	noecho();
	box(stdscr, 0,0);
	return;
}

void closeCurses(){
	endwin();
	return;
}


