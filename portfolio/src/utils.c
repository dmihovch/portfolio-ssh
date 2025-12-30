#include "../include/utils.h"

int clamp(int i, int maxi){
	if(i<1)return 1;
	if(i>maxi)return maxi;
	return i;
}
int randInRange(int,int);

void initCurses(){
	initscr();
	curs_set(0);
	noecho();
	nodelay(stdscr, 1);
	box(stdscr, 0,0);
	return;
}

void closeCurses(){
	endwin();
	return;
}


