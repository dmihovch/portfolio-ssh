#include "../include/utils.h"
#include <ncurses.h>

int clamp(int i, int maxi){
	if(i<1)return 1;
	if(i>maxi)return maxi;
	return i;
}

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

void handleResize(Page* pages, int num_pages){

	for(int i = 0; i<num_pages; i++){
		box(pages[i].win,0,0);
	}
}

