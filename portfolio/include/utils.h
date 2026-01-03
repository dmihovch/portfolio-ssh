

#ifndef UTILS_H
#define UTILS_H

#include "page.h"
#include <ncurses.h>


void handleResize(Page* pages, int num_pages);




int clamp(int, int);
void initCurses();
void closeCurses();

#endif
