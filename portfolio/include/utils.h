#pragma once
#include <ncurses.h>



#define boxRefresh(win)		\
	box(win, 0, 0);			\
	wrefresh(win);			\
	



void clampx(int*, int);
void clampy(int*, int);
void initCurses();
void closeCurses();

