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

View newView(int nlines, int ncols, int begin_y, int begin_x){
	View v;
	v.win = newwin(nlines,ncols,begin_y,begin_x);
	if(v.win == NULL) {
		v.ok = false;
		return (View){0};
	}
	v.pan = new_panel(v.win);
	if(v.pan == NULL){
		delwin(v.win);
		v.ok = false;
		return (View){0};
	} 
	v.ok = true;
	v.resize = true; 
	return v;
}

void freeView(View v){
	if(v.pan) del_panel(v.pan);
	if(v.win) delwin(v.win);
}

void handleResize(View* pages, int npages){
	WINDOW* curwin;
	for(int i = 0; i<npages; i++){
		curwin = pages[i].win;
		wclear(curwin);
		wresize(curwin,LINES,COLS);
		box(curwin,0,0);
	}
}



