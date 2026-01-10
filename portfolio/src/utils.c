#include "../include/utils.h"
#include <ncurses.h>
//ya ts funky 
int clamp(int i, int maxi){
	if(i<1)return 1;
	if(i>maxi)return maxi;
	return i;
}

void initCurses(){
	initscr();
	curs_set(0);
	noecho();
	return;
}

void closeCurses(){
	endwin();
	return;
}

void windowOptions(WINDOW* win){
	keypad(win, TRUE);
	nodelay(win, TRUE);
	return;
}
	











