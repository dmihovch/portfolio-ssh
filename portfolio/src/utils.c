#include "../include/utils.h"

void initCurses(){
	initscr();
	curs_set(0);
	noecho();
}

void closeCurses(){
	endwin();
}

