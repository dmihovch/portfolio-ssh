#ifndef HOME_H
#define HOME_H
#include "utils.h"
#include <ncurses.h>
#include <panel.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	WINDOW* win;
	PANEL* pan;
} Home;

//incase add more subwins and such i suppose
Home* initHome(int maxy, int maxx);
void freeHome(Home* home);
void redrawHome(Home*, int maxy, int maxx);




#endif
