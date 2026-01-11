#ifndef RESUME_H
#define RESUME_H

#include "../logs/logs.h"
#include "utils.h"
#include <string.h>
#include <ncurses.h>
#include <panel.h>
#include <stdlib.h>

//probably should not use this
#define center_text(x, text_len) x - (text_len/2)



void redrawResume(View resume,int maxy, int maxx, bool resize);
void drawEducation(WINDOW* win, int y, int x, int maxy, int maxx);
void drawExperience(WINDOW* win, int y, int x, int maxy, int maxx);
View initResume(int maxy, int maxx);

#endif
