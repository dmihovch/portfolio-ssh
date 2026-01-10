#ifndef UTILS_H
#define UTILS_H

#include <ncurses.h>
#include "../logs/logs.h"

int clamp(int, int);
void initCurses();
void closeCurses();
void windowOptions(WINDOW* win);

#endif
