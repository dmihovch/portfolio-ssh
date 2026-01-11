#ifndef UTILS_H
#define UTILS_H

#include <ncurses.h>
#include <panel.h>
#include "../logs/logs.h"

typedef struct {
	WINDOW* win;
	PANEL* pan;
	bool ok;
} View;

int clamp(int, int);
void initCurses();
void closeCurses();
void windowOptions(WINDOW* win);

//Cleans itself up if fails, returns an empty struct
View newView(int nlines, int ncols, int begin_y, int begin_x);
void freeView(View v);

void handleResize(View* pages,int npages);
#endif
